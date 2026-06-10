/*
    ResourceManager.cpp

    Implementation for the resource manager, which loads and manages game resources such as textures and audio
*/

#include "Resources/ResourceManager.hpp"
#include "Rendering/Renderer.hpp"

ResourceManager::ResourceManager() 
    : Subsystem("ResourceManager"),
      context_(*this, nullptr)
{
    addDependency<AssetManager>();
    addDependency<Renderer>();
}

void ResourceManager::resolveDependencies(Macrosystem* system) {
    context_.asset_manager = system->fetchSystem<AssetManager>();
}
