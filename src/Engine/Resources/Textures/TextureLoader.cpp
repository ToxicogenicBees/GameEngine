/*
    TextureLoader.cpp

    Implementation of an SDL3 + stb_image texture loader
*/

#include "Resources/Textures/TextureLoader.hpp"
#include "Assets/Images/ImageAsset.hpp"
#include "Core/Services.hpp"

std::shared_ptr<Texture> TextureLoader::loadFromAsset(const std::filesystem::path& local_path) {
    // Load image asset
    auto image = assetManager()->loadImage(local_path);

    // Fetch raw image data
    auto pixel_str = image->pixels();
    unsigned char* pixels = reinterpret_cast<unsigned char*>(pixel_str.data());
    
    // Generate SDL_Surface
    SDL_Surface* surface = SDL_CreateSurfaceFrom(
        image->size().width(),
        image->size().height(),
        SDL_PIXELFORMAT_RGBA32,
        pixels,
        image->size().width() * 4
    );
    if (!surface) {
        SDL_Log("SDL surface creation failed: %s", SDL_GetError());
        return nullptr;
    }

    // Create texture handle
    auto handle = SDL_CreateTextureFromSurface(Services::renderer()->raw(), surface);
    if (!handle) {
        SDL_Log("SDL texture creation failed: %s", SDL_GetError());
        SDL_DestroySurface(surface);
        return nullptr;
    }

    // Free surface memory
    SDL_DestroySurface(surface);

    // Return texture resource
    return std::make_unique<Texture>(handle, image->size());
}
