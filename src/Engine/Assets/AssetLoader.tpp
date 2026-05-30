/*
    AssetLoader.tpp

    Template implementation for an asset loader, in charge of loading and caching assets from system files.
*/

#pragma once

#include "Assets/AssetLoader.hpp"

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
AssetLoader<Asset_t>::AssetLoader(const std::filesystem::path& subfolder)
    : SUBFOLDER_(subfolder) {}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
std::shared_ptr<Asset_t> AssetLoader<Asset_t>::fetch(const std::filesystem::path& path) {
    // Return cached asset if found
    auto iter = assets_.find(path);
    if (iter != assets_.end())
        return iter->second;

    // Load the desired asset
    auto asset = loadFromFile(path);
    if (!asset)
        throw std::runtime_error("Invalid asset: " + path.string());

    // Cache and return the loaded asset
    assets_[path] = asset;
    return asset;
}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
std::filesystem::path AssetLoader<Asset_t>::subfolder() const {
    return SUBFOLDER_;
}
