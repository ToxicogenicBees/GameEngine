/*
    ImageLoader.hpp

    Declaration of an stb_image image loader
*/

#pragma once

#include "Assets/AssetLoader.hpp"
#include "Assets/Images/Image.hpp"
#include <SDL3/SDL.h>
#include <filesystem>
#include <memory>

class ImageLoader : public AssetLoader<Image> {
protected:
    /**
     * @brief Loads a texture from memory
     * 
     * @param path Filename of the texture
     */
    std::shared_ptr<Image> loadFromFile(const std::filesystem::path& assets_directory, const std::filesystem::path& local_path) override;

public:
    /**
     * @brief Constructor.
     * 
     * @param subfolder The subfolder in the assets folder this loader searches in.
     */
    ImageLoader(const std::filesystem::path& subfolder);
};
