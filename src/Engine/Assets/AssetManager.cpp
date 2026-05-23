/*
    AssetManager.cpp

    Implementation for the asset manager, which loads and manages game assets such as sprites
*/

#include "Assets/AssetManager.hpp"
#include <string>

namespace {
    constexpr uint8_t ASSET_SEARCH_DEPTH = 5; // Maximum depth to search for assets within the assets directory

    const std::string ASSET_FOLDER_NAME = "assets";
    const std::string TEXTURE_FOLDER_NAME = "textures";
}

std::filesystem::path AssetManager::getAssetPath_(const std::string& asset_folder, const std::filesystem::path& local_path) {
    return folder_path_ / asset_folder /local_path;
}

AssetManager::AssetManager(Renderer& renderer)
    : renderer_(renderer)
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

std::shared_ptr<Texture> AssetManager::loadTexture(const std::filesystem::path& local_path) {
    // Check if the asset is already loaded, and return it if it does
    auto path = getAssetPath_(TEXTURE_FOLDER_NAME, local_path);
    if (assets_.find(path) != assets_.end())
        return std::static_pointer_cast<Texture>(assets_[path]);
    
    // Load the texture from the file
    auto texture = std::make_shared<Texture>(path);
    texture->loadFromFile(renderer_.raw(), path);

    // Store texture in the cache and return it
    assets_[path] = std::static_pointer_cast<Asset>(texture);
    return texture;
}
