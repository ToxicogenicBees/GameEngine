/*
    ImageAssetLoader.cpp

    Implementation of an SDL3 + stb_image image loader
*/

#include "Assets/Loaders/ImageAssetLoader.hpp"
#include "Logging/Logger.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <format>

std::shared_ptr<ImageAsset> ImageAssetLoader::loadFromFile(const std::filesystem::path& asset_directory, const std::filesystem::path& local_path) {
    // Fetch global file path
    auto path = asset_directory / local_path;

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
        ENGINE_ERROR(ASSET, std::format(
            "Failed to load image \"{}\" ({})",
            local_path.string(),
            stbi_failure_reason()
        ));
        return nullptr;
    }

    // Make new image
    auto image = std::make_shared<ImageAsset>(data, Size{static_cast<size_t>(width), static_cast<size_t>(height)});

    // Free stb_image memory
    stbi_image_free(data);

    // Return image
    return image;
}

ImageAssetLoader::ImageAssetLoader()
    : AssetLoader({".png", ".jpg"})
{}
