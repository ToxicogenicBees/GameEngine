/*
    TextureLoader.hpp

    Declaration of an SDL3 + stb_image texture loader
*/

#pragma once

#include "Assets/Texturing/Texture.hpp"
#include <SDL3/SDL.h>
#include <filesystem>
#include <memory>

class TextureLoader {
public:
    /**
     * @brief Loads a texture from memory
     * 
     * @param path Filename of the texture
     */
    static std::shared_ptr<Texture> load(const std::filesystem::path& path);
};
