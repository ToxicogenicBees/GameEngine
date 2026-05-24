/*
    TextureLoader.cpp

    Implementation of an SDL3 + stb_image texture loader
*/

#include "Assets/TextureLoader.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

std::shared_ptr<Texture> TextureLoader::load(SDL_Renderer* renderer, const std::filesystem::path& path) {
    int channels, width, height;

    unsigned char* data = stbi_load(
        path.string().c_str(),
        &width,
        &height,
        &channels,
        4
    );

    if (!data) {
        SDL_Log("stb_image failed: %s", stbi_failure_reason());
        return nullptr;
    }

    std::string pixels((char*)data, width * height * 4);

    SDL_Surface* surface = SDL_CreateSurfaceFrom(
        width,
        height,
        SDL_PIXELFORMAT_RGBA32,
        data,
        width * 4
    );

    if (!surface) {
        SDL_Log("SDL surface creation failed: %s", SDL_GetError());
        stbi_image_free(data);
        return nullptr;
    }

    auto handle = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_DestroySurface(surface);
    stbi_image_free(data);

    if (!handle) {
        SDL_Log("SDL texture creation failed: %s", SDL_GetError());
        return nullptr;
    }

    return std::make_unique<Texture>(handle, pixels, Size{(size_t)width, (size_t)height});
}
