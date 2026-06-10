/*
    AssetLoader.tpp

    Template implementation for an asset loader, in charge of loading and caching assets from system files.
*/

#pragma once

#include "Assets/AssetLoader.hpp"
#include "Logging/Logger.hpp"
#include <format>

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
template<typename... Args>
std::pair<Handle<Asset_t>, Asset_t*> AssetLoader<Asset_t>::createHandle(Args&& ...args) {
    return assets_.create(std::forward<Args>(args)...);
}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
AssetLoader<Asset_t>::AssetLoader(AssetLoaderContext& context, const std::vector<std::filesystem::path> extension_whitelist)
    : EXTENSION_WHITELIST_(extension_whitelist),
      context_(context)
{}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
AssetRecordHandle<Asset_t> AssetLoader<Asset_t>::fetch(const std::filesystem::path& local_path) {
    // Attempt to fetch from cache
    auto cached = cache_.find(local_path);
    if (cached != cache_.end())
        return cached->second;

    // Load asset directly
    auto [asset_handle, asset_ptr] = loadFromFile(local_path);
    
    // Construct and cache record
    auto [record_handle, record_ptr] = records_.create(local_path, asset_handle);
    cache_[local_path] = record_handle;

    // Send log
    ENGINE_DEBUG(ASSET, std::format(
        "Loaded {} \"{}\"",
        asset_ptr->type(),
        local_path.string()
    ));

    // Return record
    return record_handle;
}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
Asset_t* AssetLoader<Asset_t>::resolve(AssetRecordHandle<Asset_t> handle) {
    auto* record = records_.resolve(handle);

    if (!record)
        return nullptr;

    if (!record->isLoaded()) {
        // Load asset directly
        auto [asset_handle, _] = loadFromFile(record->path());

        // Reload record with the new handle
        record->load(asset_handle);
    }

    return assets_.resolve(record->handle());
}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
bool AssetLoader<Asset_t>::supports(const std::filesystem::path& extension) const {
    // If no extensions are specified, assume all files are allowed
    if (EXTENSION_WHITELIST_.empty())
        return true;
    
    // Search whitelist
    auto iter = std::find(EXTENSION_WHITELIST_.begin(), EXTENSION_WHITELIST_.end(), extension);
    return (iter != EXTENSION_WHITELIST_.end());
}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
AssetLoaderContext& AssetLoader<Asset_t>::context() {
    return context_;
}
