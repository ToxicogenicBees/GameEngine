/*
    AssetManager.hpp

    Declaration for the asset manager, which loads and manages game assets such as images and audio files
*/

#pragma once

#include "Core/System/Subsystem.hpp"
#include "Assets/Images/ImageAssetLoader.hpp"
#include "Assets/Images/ImageAsset.hpp"
#include <unordered_map>
#include <filesystem>
#include <mutex>

class AssetManager final : public Subsystem {
private:
    std::filesystem::path folder_path_;

    ImageAssetLoader image_loader_;

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
    std::shared_ptr<ImageAsset> loadImage(const std::filesystem::path& local_path);
};
