/*
    IResourceLoader.hpp

    An interface for a resource loader.
*/

#pragma once

#include "Assets/AssetManager.hpp"
#include <filesystem>
#include <typeindex>
#include <memory>

class IResourceLoader {
public:
    /**
     * @brief Loads a resource with an erased type.
     * 
     * @param asset_manager Pointer to the asset manager.
     * @param local_path The local path to the asset.
     */
    virtual std::shared_ptr<void> loadErased(AssetManager* asset_manager, const std::filesystem::path& local_path) = 0;

    /**
     * @brief Get the source type of this loader.
     * 
     * @return The source type of this loader.
     */
    virtual std::type_index sourceType() const = 0;

    /**
     * @brief Get the source type of this loader.
     * 
     * @return The source type of this loader.
     */
    virtual std::type_index resourceType() const = 0;

    /**
     * @brief Destructor.
     */
    virtual ~IResourceLoader() = default;
};