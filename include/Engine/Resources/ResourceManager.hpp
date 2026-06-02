/*
    ResourceManager.hpp

    Declaration for the resource manager, which loads and manages game resources such as textures and audio
*/

#pragma once

#include "Assets/AssetManager.hpp"
#include "Resources/Textures/Texture.hpp"
#include "Resources/Textures/TextureLoader.hpp"
#include <unordered_map>
#include <filesystem>
#include <mutex>

class ResourceManager {
private:
    std::filesystem::path folder_path_;
    AssetManager& asset_manager_;
    TextureLoader texture_loader_;

public:
    /**
     * @brief Constructor
     */
    ResourceManager(AssetManager& asset_manager);

    /**
     * @brief Load the desired texture
     * 
     * @param local_path The path to the asset relative to the asset type folder.
     * @return The loaded asset.
     */
    std::shared_ptr<Texture> loadTexture(const std::filesystem::path& local_path);
};
