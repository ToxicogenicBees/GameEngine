/*
    AssetManager.hpp

    Declaration for the asset manager, which loads and manages game assets such as sprites
*/

#pragma once

#include "Rendering/Texture.hpp"
#include <unordered_map>
#include <SDL3/SDL.h>
#include <filesystem>
#include <mutex>

class AssetManager {
private:
    std::unordered_map<std::filesystem::path, std::shared_ptr<Asset>> assets_;
    std::filesystem::path folder_path_;
    SDL_Renderer* renderer_;

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
    AssetManager(SDL_Renderer* renderer);

    /**
     * @brief Constructor
     * 
     * @param renderer Reference to the SDL_Renderer pointer used for loading textures
     */
    AssetManager(SDL_Renderer*& renderer);

    /**
     * @brief Load the desired texture
     * 
     * @param local_path The path to the asset relative to the asset type folder.
     * @return The loaded asset.
     */
    std::shared_ptr<Texture> loadTexture(const std::filesystem::path& local_path);
};
