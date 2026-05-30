/*
    AssetManager.hpp

    Declaration for the asset manager, which loads and manages game assets such as sprites
*/

#pragma once

#include "Core/Interfaces/IService.hpp"
#include "Assets/Texturing/Texture.hpp"
#include "Assets/Texturing/TextureLoader.hpp"
#include <unordered_map>
#include <filesystem>
#include <mutex>

class AssetManager final : public IService {
private:
    std::filesystem::path folder_path_;

    TextureLoader texture_loader_;

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
