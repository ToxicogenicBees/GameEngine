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
AssetLoader<Asset_t>::AssetLoader(const std::filesystem::path& subfolder, std::optional<std::filesystem::path> default_asset)
    : SUBFOLDER_(subfolder), DEFAULT_ASSET_(default_asset) {}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
std::shared_ptr<Asset_t> AssetLoader<Asset_t>::fetch(const std::filesystem::path& assets_directory, const std::filesystem::path& local_path) {
    // Fetch local assets directory
    auto directory = assets_directory / SUBFOLDER_;

    // Attempt to load a file
    auto load = [this](const std::filesystem::path& assets_directory, const std::filesystem::path& local_path) -> std::shared_ptr<Asset_t> {
        // Build full path
        auto path = assets_directory / subfolder() / local_path;

        // Search cache for asset
        auto iter = assets_.find(path);
        if (iter != assets_.end())
            return iter->second;

        // Fetch asset from disc and cache
        auto asset = loadFromFile(assets_directory, local_path);
        if (asset) {
            assets_[path] = asset;
            return asset;
        }
        
        // Failed to load asset
        return nullptr;
    };

    // Fetch desired asset
    auto asset = load(assets_directory, local_path);
    if (asset)
        return asset;

    // Failed to fetch asset, fetch default asset
    ENGINE_ERROR("Failed to fetch asset \"" + local_path.string() + "\"");
    if (DEFAULT_ASSET_) {
        asset = load(assets_directory, DEFAULT_ASSET_.value());
        if (asset)
            return asset;
    }

    // Engine failure due to failing to load any asset
    if (DEFAULT_ASSET_)
        ENGINE_FATAL("Failed to fetch default asset \"" + DEFAULT_ASSET_.value().string() + "\"");
    else
        ENGINE_FATAL("No default asset to replace \"" + local_path.string() + "\"");

    return nullptr;
}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
std::filesystem::path AssetLoader<Asset_t>::subfolder() const {
    return SUBFOLDER_;
}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
std::optional<std::filesystem::path> AssetLoader<Asset_t>::defaultAsset() const {
    return DEFAULT_ASSET_;
}
