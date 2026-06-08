/*
    ResourceLoader.hpp

    Declaration for a resource loader, in charge of loading and caching resources from assets / runtime data.
*/

#pragma once

#include "Resources/Interfaces/IResourceLoader.hpp"
#include "Assets/AssetManager.hpp"
#include "Resources/Resource.hpp"
#include "Assets/Asset.hpp"
#include <unordered_map>
#include <filesystem>
#include <concepts>
#include <memory>

template<typename Asset_t, typename Resource_t>
requires std::is_base_of_v<Asset, Asset_t> && std::is_base_of_v<Resource, Resource_t> 
class ResourceLoader : public IResourceLoader {
private:
    std::unordered_map<std::shared_ptr<Asset_t>, std::shared_ptr<Resource_t>> resources_;

protected:
    /**
     * @brief Loads a resource from an asset.
     * 
     * @param asset The asset used for this resource.
     */
    virtual std::shared_ptr<Resource_t> loadFromAsset(std::shared_ptr<Asset_t> asset) = 0;

public:
    using AssetType = Asset_t;
    using ResourceType = Resource_t;

    /**
     * @brief Constructor.
     */
    ResourceLoader() = default;

    /**
     * @brief Loads a resource with an erased type.
     * 
     * @param asset_manager Pointer to the asset manager.
     * @param local_path The local path to the asset.
     */
    std::shared_ptr<void> loadErased(AssetManager* asset_manager, const std::filesystem::path& local_path) final;

    /**
     * @brief Get the source type of this loader.
     * 
     * @return The source type of this loader.
     */
    std::type_index sourceType() const final;

    /**
     * @brief Get the source type of this loader.
     * 
     * @return The source type of this loader.
     */
    std::type_index resourceType() const final;
};

#include "Resources/ResourceLoader.tpp"
