/*
    ResourceLoader.cpp

    Template implementation for a resource loader, in charge of loading and caching resources from assets / runtime data.
*/

#include "Resources/ResourceLoader.hpp"

template<typename Resource_t>
requires std::is_base_of_v<Resource, Resource_t> 
template<typename... Args>
std::pair<Handle<Resource_t>, Resource_t*> ResourceLoader<Resource_t>::createHandle(Args&& ...args) {
    return resources_.create(std::forward<Args>(args)...);
}

template<typename Resource_t>
requires std::is_base_of_v<Resource, Resource_t> 
ResourceLoader<Resource_t>::ResourceLoader(ResourceLoaderContext& context)
    : context_(context) {}

template<typename Resource_t>
requires std::is_base_of_v<Resource, Resource_t> 
ResourceRecordHandle<Resource_t> ResourceLoader<Resource_t>::fetch(const std::filesystem::path& local_path) {
    // Attempt to fetch from cache
    auto cached = cache_.find(local_path);
    if (cached != cache_.end())
        return cached->second;

    // Load resource directly
    using Asset_t = typename Resource_t::AssetType;
    auto asset_handle = context_.asset_manager->load<Asset_t>(local_path);
    auto asset_ptr = context_.asset_manager->resolve(asset_handle);
    auto [resource_handle, resource_ptr] = loadFromAsset(asset_ptr);
    
    // Construct and cache record
    auto [record_handle, record_ptr] = records_.create(local_path, resource_handle);
    cache_[local_path] = record_handle;

    // Send log
    ENGINE_DEBUG(RESOURCE, std::format(
        "Loaded {} \"{}\"",
        resource_ptr->type(),
        local_path.string()
    ));

    // Return record
    return record_handle;
}

template<typename Resource_t>
requires std::is_base_of_v<Resource, Resource_t> 
Resource_t* ResourceLoader<Resource_t>::resolve(ResourceRecordHandle<Resource_t> handle) {
    auto* record = records_.resolve(handle);

    if (!record)
        return nullptr;

    if (!record->isLoaded()) {
        // Load resource directly
        using Asset_t = typename Resource_t::AssetType;
        auto asset_handle = context_.asset_manager->load<Asset_t>(record->path());
        auto asset_ptr = context_.asset_manager->resolve(asset_handle);
        auto [resource_handle, resource_ptr] = loadFromAsset(asset_ptr);

        // Load the record with the new handle
        record->load(resource_handle);
    }

    return resources_.resolve(record->handle());
}

template<typename Resource_t>
requires std::is_base_of_v<Resource, Resource_t> 
ResourceLoaderContext& ResourceLoader<Resource_t>::context() {
    return context_;
}
