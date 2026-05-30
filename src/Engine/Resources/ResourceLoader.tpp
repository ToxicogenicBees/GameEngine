/*
    ResourceLoader.tpp

    Template implementation for a resource loader, in charge of loading and caching resources from assets / runtime data.
*/

#pragma once

#include "Resources/ResourceLoader.hpp"

template<typename Resource_t>
requires std::is_base_of_v<Resource, Resource_t>
ResourceLoader<Resource_t>::ResourceLoader(AssetManager& asset_manager)
    : asset_manager_(asset_manager) {}

template<typename Resource_t>
requires std::is_base_of_v<Resource, Resource_t>
std::shared_ptr<Resource_t> ResourceLoader<Resource_t>::fetch(const std::filesystem::path& local_path) {
    // Return cached resource if found
    auto iter = resources_.find(local_path);
    if (iter != resources_.end())
        return iter->second;

    // Load the desired resource
    auto resource = loadFromAsset(local_path);
    if (!resource)
        throw std::runtime_error("Invalid resource: " + local_path.string());

    // Cache and return the loaded resource
    resources_[local_path] = resource;
    return resource;
}

template<typename Resource_t>
requires std::is_base_of_v<Resource, Resource_t>
AssetManager& ResourceLoader<Resource_t>::assetManager() const {
    return asset_manager_;
}
