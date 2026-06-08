/*
    ResourceManager.tpp

    Template implementation for the resource manager, which loads and manages game resources such as textures and audio
*/

#pragma once

#include "Resources/ResourceManager.hpp"
#include "Resources/ResourceLoader.hpp"

template<typename ResourceLoader_t>
requires std::is_base_of_v<IResourceLoader, ResourceLoader_t>
ResourceLoader_t* ResourceManager::addLoader() {
    std::unique_ptr<ResourceLoader_t> loader = std::make_unique<ResourceLoader_t>();
    auto* ptr = loader.get();

    loaders_[typeid(typename ResourceLoader_t::ResourceType)] = std::move(loader);
    return ptr;
}

template<typename Resource_t>
requires std::is_base_of_v<Resource, Resource_t> || std::is_same_v<Resource, Resource_t>
std::shared_ptr<Resource_t> ResourceManager::load(const std::filesystem::path& local_path) {
    // Fetch and load from the desired loader
    if (loaders_.contains(typeid(Resource_t))) {
        return std::static_pointer_cast<Resource_t>(
            loaders_[typeid(Resource_t)]->loadErased(asset_manager_, local_path)
        );
    }

    // Failed to load
    ENGINE_FATAL(RESOURCE, std::format(
        "Couldn't fetch resource \"{}\"; no loader supports the asset type",
        local_path.string()
    ));
    return nullptr;
}
