/*
    ResourceLoader.hpp

    Declaration for a resource loader, in charge of loading and caching resources from assets / runtime data.
*/

#pragma once

#include "Assets/AssetManager.hpp"
#include "Resources/Resource.hpp"
#include <unordered_map>
#include <filesystem>
#include <concepts>
#include <memory>

template<typename Resource_t>
requires std::is_base_of_v<Resource, Resource_t>
class ResourceLoader {
private:
    std::unordered_map<std::filesystem::path, std::shared_ptr<Resource_t>> resources_;
    AssetManager& asset_manager_;

protected:
    /**
     * @brief Loads an asset from a specified file path.
     * 
     * @param local_path The path to the desired file.
     */
    virtual std::shared_ptr<Resource_t> loadFromAsset(const std::filesystem::path& local_path) = 0;

public:
    /**
     * @brief Constructor.
     * 
     * @param subfolder The subfolder in the assets folder this loader searches in.
     */
    ResourceLoader(AssetManager& asset_manager);

    /**
     * @brief Loads a texture from memory.
     * 
     * @param local_path Filename of the texture.
     */
    std::shared_ptr<Resource_t> fetch(const std::filesystem::path& local_path);

    /**
     * @brief Gets the subfolder for this asset loader.
     * 
     * @return The subfolder for this asset loader.
     */
    AssetManager& assetManager() const;

    /**
     * @brief Destructor.
     */
    virtual ~ResourceLoader() = default;
};

#include "Resources/ResourceLoader.tpp"
