/*
    ResourceManager.cpp

    Implementation for the resource manager, which loads and manages game resources such as textures and audio
*/

#include "Resources/ResourceManager.hpp"
#include "Rendering/Renderer.hpp"

ResourceManager::ResourceManager() 
    : Subsystem("ResourceManager")
{
    addDependency<AssetManager>();
    addDependency<Renderer>();
}

void ResourceManager::resolveDependencies(Macrosystem* system) {
    asset_manager_ = system->fetchSystem<AssetManager>();
}

AssetManager* ResourceManager::assetManager() const {
    return asset_manager_;
}
