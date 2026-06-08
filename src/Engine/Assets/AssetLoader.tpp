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
AssetLoader<Asset_t>::AssetLoader(const std::vector<std::filesystem::path> supported_extensions, std::optional<std::filesystem::path> default_asset)
    : SUPPORTED_EXTENSIONS_(supported_extensions),
      DEFAULT_ASSET_(default_asset)
{}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
std::shared_ptr<void> AssetLoader<Asset_t>::loadErased(const std::filesystem::path& asset_directory, const std::filesystem::path& local_path) {
    // Attempt to load a file
    auto load = [this, asset_directory](const std::filesystem::path& path) -> std::shared_ptr<Asset_t> {
        // Search cache for asset
        auto iter = assets_.find(path);
        if (iter != assets_.end())
            return iter->second;

        // Fetch asset from disc and cache
        auto asset = loadFromFile(asset_directory, path);
        if (asset) {
            ENGINE_DEBUG(ASSET, "Loaded asset \"" + path.string() + "\"");
            assets_[path] = asset;
            return asset;
        }
        
        // Failed to load asset
        return nullptr;
    };

    // Fetch desired asset
    auto asset = load(local_path);
    if (asset)
        return std::static_pointer_cast<void>(asset);

    // Failed to fetch asset, fetch default asset
    ENGINE_ERROR(ASSET, "Failed to fetch asset \"" + local_path.string() + "\"");
    if (DEFAULT_ASSET_) {
        asset = load(DEFAULT_ASSET_.value());
        if (asset)
            return std::static_pointer_cast<void>(asset);
    }

    // Engine failure due to failing to load any asset
    if (DEFAULT_ASSET_)
        ENGINE_FATAL(ASSET, "Failed to fetch default asset \"" + DEFAULT_ASSET_.value().string() + "\"");
    else
        ENGINE_FATAL(ASSET, "No default asset to replace \"" + local_path.string() + "\"");

    return nullptr;
}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
std::optional<std::filesystem::path> AssetLoader<Asset_t>::defaultAsset() const {
    return DEFAULT_ASSET_;
}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
std::type_index AssetLoader<Asset_t>::assetType() const {
    return typeid(Asset_t);
}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
bool AssetLoader<Asset_t>::supports(const std::filesystem::path& extension) const {
    auto iter = std::find(SUPPORTED_EXTENSIONS_.begin(), SUPPORTED_EXTENSIONS_.end(), extension);
    return (iter != SUPPORTED_EXTENSIONS_.end());
}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
const std::vector<std::filesystem::path>& AssetLoader<Asset_t>::extensions() const {
    return SUPPORTED_EXTENSIONS_;
}
