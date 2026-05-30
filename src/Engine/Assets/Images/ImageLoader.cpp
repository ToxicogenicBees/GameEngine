/*
    ImageLoader.cpp

    Implementation of an SDL3 + stb_image image loader
*/

#include "Assets/Images/ImageLoader.hpp"
#include "Core/Services.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

std::shared_ptr<Image> ImageLoader::loadFromFile(const std::filesystem::path& path) {
    // Load the image through stbi_load
    int channels, width, height;
    unsigned char* data = stbi_load(
        path.string().c_str(),
        &width,
        &height,
        &channels,
        4
    );

    // Throw an error if the image failed to load
    if (!data) {
        SDL_Log("stb_image failed: %s", stbi_failure_reason());
        return nullptr;
    }

    // Fetch pixel data as a string
    std::string pixels((char*)data, width * height * 4);

    // Free stb_image memory
    stbi_image_free(data);

    // Return new image
    return std::make_unique<Image>(path, pixels, Size{(size_t)width, (size_t)height});
}

ImageLoader::ImageLoader(const std::filesystem::path& subfolder)
    : AssetLoader<Image>(subfolder) {}
