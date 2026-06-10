/*
    ResourceLoader.hpp

    Declaration for a resource loader, in charge of loading and caching resources from assets / runtime data.
*/

#pragma once

#include "Resources/Interfaces/IResourceLoader.hpp"
#include "Resources/ResourceLoaderContext.hpp"
#include "Resources/ResourceRecord.hpp"
#include "Assets/AssetManager.hpp"
#include "Resources/Resource.hpp"
#include "Assets/AssetRecord.hpp"
#include "Assets/Asset.hpp"
#include "Core/Handle.hpp"
#include <unordered_map>
#include <filesystem>
#include <concepts>
#include <memory>

template<typename Resource_t>
requires std::is_base_of_v<Resource, Resource_t> 
class ResourceLoader : public IResourceLoader {
private:
    // Resource management
    std::unordered_map<std::filesystem::path, ResourceRecordHandle<Resource_t>> cache_;
    HandleBuffer<ResourceRecord<Resource_t>> records_;
    HandleBuffer<Resource_t> resources_;

    // Context
    ResourceLoaderContext& context_;

protected:
    /**
     * @brief Loads a resource from an asset.
     * 
     * @param asset The asset used for this resource.
     */
    virtual std::pair<Handle<Resource_t>, Resource_t*> loadFromAsset(Resource_t::AssetType* asset) = 0;

    /**
     * @brief Creates a handle for the desired resource.
     * 
     * @param args... The constructor arguments for the resource.
     */
    template<typename... Args>
    std::pair<Handle<Resource_t>, Resource_t*> createHandle(Args&& ...args);

public:
    using ResourceType = Resource_t;

    /**
     * @brief Constructor.
     * 
     * @param context The context for this resource loader.
     */
    ResourceLoader(ResourceLoaderContext& context);
    
    /**
     * @brief Fetches an resource handle for the desired resource.
     * 
     * @param local_path The local path to the resource's asset.
     * @return A handle to the desired resource.
     */
    ResourceRecordHandle<Resource_t> fetch(const std::filesystem::path& local_path);

    /**
     * @brief Resolves an resource handle.
     * 
     * @return The resolved resource pointer.
     */
    Resource_t* resolve(ResourceRecordHandle<Resource_t> handle);

    /**
     * @brief Gets this loader's context.
     * 
     * @return The loader's context.
     */
    ResourceLoaderContext& context();
};

#include "Resources/ResourceLoader.tpp"
