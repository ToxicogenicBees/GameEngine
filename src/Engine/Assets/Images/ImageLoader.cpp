/*
    ImageLoader.cpp

    Implementation of an SDL3 + stb_image image loader
*/

#include "Assets/Images/ImageLoader.hpp"
#include "Logging/Logger.hpp"
#include "Core/Services.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <format>

std::shared_ptr<Image> ImageLoader::loadFromFile(const std::filesystem::path& assets_directory, const std::filesystem::path& local_path) {
    // Fetch global file path
    auto path = assets_directory / subfolder() / local_path;

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
        ENGINE_ERROR(std::format(
            "Failed to load image `{}`: {}",
            local_path.string(),
            stbi_failure_reason()
        ));
        return nullptr;
    }

    // Make new image
    auto image = std::make_unique<Image>(data, Size{static_cast<size_t>(width), static_cast<size_t>(height)});

    // Free stb_image memory
    stbi_image_free(data);

    // Return image
    return image;
}

ImageLoader::ImageLoader(const std::filesystem::path& subfolder)
    : AssetLoader<Image>(subfolder) {}
