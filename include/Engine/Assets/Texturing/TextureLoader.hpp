/*
    TextureLoader.hpp

    Declaration of an SDL3 + stb_image texture loader
*/

#pragma once

#include "Assets/AssetLoader.hpp"
#include "Assets/Texturing/Texture.hpp"
#include <SDL3/SDL.h>
#include <filesystem>
#include <memory>

class TextureLoader : public AssetLoader<Texture> {
protected:
    /**
     * @brief Loads a texture from memory
     * 
     * @param path Filename of the texture
     */
    std::shared_ptr<Texture> loadFromFile(const std::filesystem::path& path) override;

public:
    /**
     * @brief Constructor.
     * 
     * @param subfolder The subfolder in the assets folder this loader searches in.
     */
    TextureLoader(const std::filesystem::path& subfolder);
};
