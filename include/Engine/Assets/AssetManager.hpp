/*
    AssetManager.hpp

    Declaration for the asset manager, which loads and manages game assets such as images and audio files
*/

#pragma once

#include "Core/System/Subsystem.hpp"
#include "Assets/Interfaces/IAssetLoader.hpp"
#include "Assets/AssetLoaderContext.hpp"
#include "Assets/AssetLoader.hpp"
#include "Assets/Asset.hpp"
#include "Core/Handle.hpp"
#include <unordered_map>
#include <filesystem>
#include <typeindex>
#include <concepts>

class AssetManager final : public Subsystem {
private:
    std::unordered_map<std::type_index, std::unique_ptr<IAssetLoader>> loaders_;
    std::filesystem::path assets_directory_;
    AssetLoaderContext context_;

public:
    /**
     * @brief Constructor
     */
    AssetManager();

    /**
     * @brief Adds an asset loader to the asset manager.
     * 
     * @param args... Constructor arguments for the desired loader.
     */
    template<typename AssetLoader_t>
    requires std::is_base_of_v<IAssetLoader, AssetLoader_t>
    AssetLoader_t* addLoader();

    /**
     * @brief Load the desired asset.
     * 
     * @param local_path The path to the asset relative to the asset type folder.
     * @return The loaded asset.
     */
    template<typename Asset_t>
    requires std::is_base_of_v<Asset, Asset_t>
    AssetRecordHandle<Asset_t> load(const std::filesystem::path& local_path);
    
    /**
     * @brief Resolves an asset handle.
     * 
     * @return The resolved asset pointer.
     */
    template<typename Asset_t>
    requires std::is_base_of_v<Asset, Asset_t>
    Asset_t* resolve(AssetRecordHandle<Asset_t> handle);
};

#include "Assets/AssetManager.tpp"
