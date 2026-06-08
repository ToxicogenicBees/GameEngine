/*
    ResourceLoader.cpp

    Template implementation for a resource loader, in charge of loading and caching resources from assets / runtime data.
*/

#include "Resources/ResourceLoader.hpp"

template<typename Asset_t, typename Resource_t>
requires std::is_base_of_v<Asset, Asset_t> && std::is_base_of_v<Resource, Resource_t> 
std::shared_ptr<void> ResourceLoader<Asset_t, Resource_t>::loadErased(AssetManager* asset_manager, const std::filesystem::path& local_path) {
    // Fetch asset
    auto asset = asset_manager->load<Asset_t>(local_path);
    
    // Return cached resource if found
    auto iter = resources_.find(asset);
    if (iter != resources_.end())
        return std::static_pointer_cast<void>(iter->second);

    // Load the desired resource
    auto resource = loadFromAsset(asset);
    if (!resource) {
        ENGINE_FATAL(RESOURCE, "Failed to fetch resource");
        return nullptr;
    }

    // Cache and return the loaded resource
    resources_[asset] = resource;
    return std::static_pointer_cast<void>(resource);
}

template<typename Asset_t, typename Resource_t>
requires std::is_base_of_v<Asset, Asset_t> && std::is_base_of_v<Resource, Resource_t>
std::type_index ResourceLoader<Asset_t, Resource_t>::sourceType() const {
    return typeid(Asset_t);
}

template<typename Asset_t, typename Resource_t>
requires std::is_base_of_v<Asset, Asset_t> && std::is_base_of_v<Resource, Resource_t>
std::type_index ResourceLoader<Asset_t, Resource_t>::resourceType() const {
    return typeid(Resource_t);
}
