/*
    ResourceManager.cpp

    Implementation for the resource manager, which loads and manages game resources such as textures and audio
*/

#include "Resources/ResourceManager.hpp"
#include "Resources/Textures/TextureLoader.hpp"

ResourceManager::ResourceManager(AssetManager& asset_manager) 
    : asset_manager_(asset_manager),
      texture_loader_(asset_manager) 
{}

std::shared_ptr<Texture> ResourceManager::loadTexture(const std::filesystem::path& local_path) {
    return texture_loader_.fetch(local_path);
}
