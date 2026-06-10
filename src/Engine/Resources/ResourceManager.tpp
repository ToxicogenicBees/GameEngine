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
    std::unique_ptr<ResourceLoader_t> loader = std::make_unique<ResourceLoader_t>(context_);
    auto* ptr = loader.get();

    loaders_[typeid(typename ResourceLoader_t::ResourceType)] = std::move(loader);
    return ptr;
}

template<typename Resource_t>
requires std::is_base_of_v<Resource, Resource_t>
ResourceRecordHandle<Resource_t> ResourceManager::load(const std::filesystem::path& local_path) {
    // Fetch and load from the desired loader
    if (loaders_.contains(typeid(Resource_t))) {
        auto* loader = static_cast<ResourceLoader<Resource_t>*>(
            loaders_[typeid(Resource_t)].get()
        );

        return loader->fetch(local_path);
    }

    else {
        // Failed to load
        ENGINE_FATAL(ASSET, std::format(
            "Cannot load \"{}\"; no loader supports the resource type \"{}\"",
            local_path.string(),
            typeid(Resource_t).name()
        ));
        return {};
    }
}

template<typename Resource_t>
requires std::is_base_of_v<Resource, Resource_t>
Resource_t* ResourceManager::resolve(ResourceRecordHandle<Resource_t> handle) {
    // Fetch and load from the desired loader
    if (loaders_.contains(typeid(Resource_t))) {
        auto* loader = static_cast<ResourceLoader<Resource_t>*>(
            loaders_[typeid(Resource_t)].get()
        );

        return loader->resolve(handle);
    }

    else {
        // Failed to load
        ENGINE_FATAL(RESOURCE, "Failed to fetch loader to resolve resource");
        return nullptr;
    }
}
