/*
    ResourceManager.cpp

    Implementation for the resource manager, which loads and manages game resources such as textures and audio
*/

#include "Resources/ResourceManager.hpp"
#include "Resources/Textures/TextureLoader.hpp"

ResourceManager::ResourceManager() 
    : Subsystem("ResourceManager")
{
    addDependency<AssetManager>();
}

void ResourceManager::resolveDependencies(Macrosystem* system) {
    asset_manager_ = system->fetchSystem<AssetManager>();

    texture_loader_.setAssetManager(asset_manager_);
}

std::shared_ptr<Texture> ResourceManager::loadTexture(const std::filesystem::path& local_path) {
    return texture_loader_.fetch(local_path);
}

AssetManager* ResourceManager::assetManager() const {
    return asset_manager_;
}
