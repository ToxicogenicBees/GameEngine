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
    std::unique_ptr<AssetLoader_t> loader = std::make_unique<AssetLoader_t>(context_);
    auto* ptr = loader.get();

    // Store loader in maps
    loaders_[typeid(typename AssetLoader_t::AssetType)] = std::move(loader);

    // Return loader
    return ptr;
}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t> || std::is_same_v<Asset, Asset_t>
std::shared_ptr<Asset_t> AssetManager::load(const std::filesystem::path& local_path) {
    // Fetch and load from the desired loader
    auto& loader = loaders_[typeid(Asset_t)];
    auto extension = local_path.extension();
    if (loader && loader->supports(extension)) {
        return std::static_pointer_cast<Asset_t>(
            loader->loadErased(local_path)
        );
    }

    else if (loader) {
        // Loader cannot load extension
        ENGINE_FATAL(ASSET, std::format(
            "Cannot load \"{}\"; loader doesn't support \"{}\" files",
            local_path.string(),
            extension.string()
        ));
        return nullptr;
    }

    else {
        // Failed to load
        ENGINE_FATAL(ASSET, std::format(
            "Cannot load \"{}\"; no loader supports the asset type \"{}\"",
            local_path.string(),
            typeid(Asset_t).name()
        ));
        return nullptr;
    }
}
