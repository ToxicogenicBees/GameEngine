/*
    TextureLoader.hpp

    Declaration of an SDL3 + stb_image texture loader
*/

#pragma once

#include "Rendering/Texture.hpp"
#include <SDL3/SDL.h>
#include <filesystem>
#include <memory>

class TextureLoader {
public:
    /**
     * @brief Loads a texture from memory
     * 
     * @param renderer Pointer to the SDL3 renderer
     * @param path Filename of the texture
     */
    static std::shared_ptr<Texture> load(SDL_Renderer* renderer, const std::filesystem::path& path);
};
