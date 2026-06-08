/*
    ResourceManager.cpp

    Implementation for the resource manager, which loads and manages game resources such as textures and audio
*/

#include "Resources/ResourceManager.hpp"

ResourceManager::ResourceManager() 
    : Subsystem("ResourceManager")
{
    addDependency<AssetManager>();
}

void ResourceManager::resolveDependencies(Macrosystem* system) {
    asset_manager_ = system->fetchSystem<AssetManager>();
}

AssetManager* ResourceManager::assetManager() const {
    return asset_manager_;
}
