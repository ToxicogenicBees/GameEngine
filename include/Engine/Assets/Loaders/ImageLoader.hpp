/*
    ImageLoader.hpp

    Declaration of an stb_image image loader
*/

#pragma once

#include "Assets/AssetLoader.hpp"
#include "Assets/AssetLoaderContext.hpp"
#include "Assets/Types/Image.hpp"
#include "Core/Handle.hpp"
#include <filesystem>
#include <memory>

class ImageLoader final : public AssetLoader<Image> {
protected:
    /**
     * @brief Loads an image file from memory.
     * 
     * @param local_path The local path to the asset.
     */
    std::pair<Handle<Image>, Image*> loadFromFile(const std::filesystem::path& local_path) final;

public:
    /**
     * @brief Constructor.
     */
    ImageLoader(AssetLoaderContext& context);
};
