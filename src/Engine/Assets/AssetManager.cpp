/*
    AssetManager.cpp

    Implementation for the asset manager, which loads and manages game assets such as sprites
*/

#include "Assets/AssetManager.hpp"
#include <string>

namespace {
    const std::string ASSET_FOLDER_NAME = "assets";
    constexpr uint8_t ASSET_SEARCH_DEPTH = 5;

    const std::filesystem::path IMAGE_PATH = "textures";
}

AssetManager::AssetManager() 
    : Subsystem("AssetManager"),
      image_loader_(IMAGE_PATH)
{
    // Search for the assets directory starting from the current working directory and moving up the directory tree
    std::filesystem::path search_path = std::filesystem::current_path();
    for (uint8_t depth = 0; depth < ASSET_SEARCH_DEPTH; ++depth) {
        auto potential_path = search_path / ASSET_FOLDER_NAME;
        if (std::filesystem::exists(potential_path) && std::filesystem::is_directory(potential_path)) {
            folder_path_ = potential_path;
            return;
        }
        search_path = search_path.parent_path();
    }

    // If the assets directory was not found, throw an error
    throw std::runtime_error("Failed to initialize AssetManager: assets directory not found within search depth");
}

std::shared_ptr<ImageAsset> AssetManager::loadImage(const std::filesystem::path& local_path) {
    return image_loader_.fetch(folder_path_, local_path);
}
