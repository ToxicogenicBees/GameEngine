/*
    ImageAssetLoader.hpp

    Declaration of an stb_image image loader
*/

#pragma once

#include "Assets/AssetLoader.hpp"
#include "Assets/Types/ImageAsset.hpp"
#include <filesystem>
#include <memory>

class ImageAssetLoader final : public AssetLoader<ImageAsset> {
protected:
    /**
     * @brief Loads an image file from memory.
     * 
     * @param asset_directory The assets directory.
     * @param local_path The local path to the asset.
     */
    std::shared_ptr<ImageAsset> loadFromFile(const std::filesystem::path& asset_directory, const std::filesystem::path& local_path) final;

public:
    /**
     * @brief Constructor.
     */
    ImageAssetLoader();
};
