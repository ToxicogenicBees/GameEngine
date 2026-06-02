/*
    AssetManager.hpp

    Declaration for the asset manager, which loads and manages game assets such as images and audio files
*/

#pragma once

#include "Assets/Images/ImageLoader.hpp"
#include "Assets/Images/Image.hpp"
#include <unordered_map>
#include <filesystem>
#include <mutex>

class AssetManager {
private:
    std::filesystem::path folder_path_;

    ImageLoader image_loader_;

public:
    /**
     * @brief Constructor
     */
    AssetManager();

    /**
     * @brief Load the desired image
     * 
     * @param local_path The path to the asset relative to the asset type folder.
     * @return The loaded asset.
     */
    std::shared_ptr<Image> loadImage(const std::filesystem::path& local_path);
};
