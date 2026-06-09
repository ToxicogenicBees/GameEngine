/*
    AssetManager.hpp

    Declaration for the asset manager, which loads and manages game assets such as images and audio files
*/

#pragma once

#include "Core/System/Subsystem.hpp"
#include "Assets/Interfaces/IAssetLoader.hpp"
#include "Assets/Asset.hpp"
#include <unordered_map>
#include <filesystem>
#include <typeindex>
#include <concepts>
#include <memory>

class AssetManager final : public Subsystem {
private:
    std::unordered_map<std::type_index, std::unique_ptr<IAssetLoader>> loaders_;
    std::unordered_map<std::filesystem::path, IAssetLoader*> by_extension_;
    std::filesystem::path assets_directory_;

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
    requires std::is_base_of_v<Asset, Asset_t> || std::is_same_v<Asset, Asset_t>
    std::shared_ptr<Asset_t> load(const std::filesystem::path& local_path);
};

#include "Assets/AssetManager.tpp"
