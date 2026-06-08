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
AssetLoader<Asset_t>::AssetLoader(const std::vector<std::string> supported_extensions, std::optional<std::filesystem::path> default_asset)
    : SUPPORTED_EXTENTIONS_(supported_extensions),
      DEFAULT_ASSET_(default_asset)
{}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
std::shared_ptr<Asset_t> AssetLoader<Asset_t>::fetch(const std::filesystem::path& local_path) {
    // Attempt to load a file
    auto load = [this](const std::filesystem::path& path) -> std::shared_ptr<Asset_t> {
        // Search cache for asset
        auto iter = assets_.find(path);
        if (iter != assets_.end())
            return iter->second;

        // Fetch asset from disc and cache
        auto asset = loadFromFile(path);
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
        return asset;

    // Failed to fetch asset, fetch default asset
    ENGINE_ERROR(ASSET, "Failed to fetch asset \"" + local_path.string() + "\"");
    if (DEFAULT_ASSET_) {
        asset = load(DEFAULT_ASSET_.value());
        if (asset)
            return asset;
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
void AssetLoader<Asset_t>::setAssetsDirectory(const std::filesystem::path& assets_directory) {
    assets_directory_ = assets_directory;
}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
const std::filesystem::path& AssetLoader<Asset_t>::assetsDirectory() const {
    return assets_directory_;
}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
std::optional<std::filesystem::path> AssetLoader<Asset_t>::defaultAsset() const {
    return DEFAULT_ASSET_;
}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
bool AssetLoader<Asset_t>::supports(const std::filesystem::path& path) const {
    auto iter = std::find(SUPPORTED_EXTENTIONS_.begin(), SUPPORTED_EXTENTIONS_.end(), path.extension().string());
    return (iter != SUPPORTED_EXTENTIONS_.end());
}
