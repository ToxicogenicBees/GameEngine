/*
    ImageLoader.cpp

    Implementation of an SDL3 + stb_image image loader
*/

#include "Assets/Loaders/ImageLoader.hpp"
#include "Logging/Logger.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <format>

std::pair<Handle<Image>, Image*> ImageLoader::loadFromFile(const std::filesystem::path& local_path) {
    // Fetch global file path
    auto path = context().assets_directory / local_path;

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
        return {};
    }

    // Make new image
    auto result = createHandle(data, Size{static_cast<size_t>(width), static_cast<size_t>(height)});

    // Free stb_image memory
    stbi_image_free(data);

    // Return image
    return std::move(result);
}

ImageLoader::ImageLoader(AssetLoaderContext& context)
    : AssetLoader<Image>(context, {".png", ".jpg"}) {}
