/*
    AssetManager.hpp

    Declaration for the asset manager, which loads and manages game assets such as sprites
*/

#pragma once

#include "Core/Interfaces/IService.hpp"
#include "Rendering/Renderer.hpp"
#include "Rendering/Texture.hpp"
#include <unordered_map>
#include <SDL3/SDL.h>
#include <filesystem>
#include <mutex>

class AssetManager final : public IService {
private:
    std::unordered_map<std::filesystem::path, std::shared_ptr<Texture>> textures_;
    std::filesystem::path folder_path_;

    /**
     * @brief Fetch the full path for an asset
     * 
     * @param asset_folder The folder within the assets directory where the asset is located (e.g. "textures" or "sprites").
     * @param local_path The path to the asset relative to the asset folder.
     * @return The full path to the asset file.
     */
    std::filesystem::path getAssetPath_(const std::string& asset_folder, const std::filesystem::path& local_path);

public:
    /**
     * @brief Constructor
     */
    AssetManager();

    /**
     * @brief Load the desired texture
     * 
     * @param local_path The path to the asset relative to the asset type folder.
     * @return The loaded asset.
     */
    std::shared_ptr<Texture> loadTexture(const std::filesystem::path& local_path);
};
