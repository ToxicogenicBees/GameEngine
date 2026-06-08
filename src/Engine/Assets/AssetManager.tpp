/*
    AssetManager.tpp

    Template implementation for the asset manager, which loads and manages game assets such as images and audio files
*/

#pragma once

#include "Assets/AssetManager.hpp"
#include "Logging/Logger.hpp"
#include <format>

template<typename AssetLoader_t>
requires std::is_base_of_v<IAssetLoader, AssetLoader_t>
AssetLoader_t* AssetManager::addLoader() {
    // Create loader
    std::unique_ptr<AssetLoader_t> loader = std::make_unique<AssetLoader_t>();
    auto* ptr = loader.get();

    // Store loader in maps
    loaders_[typeid(typename AssetLoader_t::AssetType)] = std::move(loader);
    for (auto& extension : ptr->extensions())
        extensions_[extension] = ptr;

    // Return loader
    return ptr;
}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t> || std::is_same_v<Asset, Asset_t>
std::shared_ptr<Asset_t> AssetManager::load(const std::filesystem::path& local_path) {
    // Fetch and load from the desired loader
    auto* loader = extensions_[local_path.extension()];
    if (loader) {
        return std::static_pointer_cast<Asset_t>(
            loader->loadErased(assets_directory_, local_path)
        );
    }

    // Failed to load
    ENGINE_FATAL(ASSET, std::format(
        "Cannot load \"{}\"; no loader supports the file extension",
        local_path.string()
    ));
    return nullptr;
}
