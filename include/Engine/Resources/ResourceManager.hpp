/*
    ResourceManager.hpp

    Declaration for the resource manager, which loads and manages game resources such as textures and audio
*/

#pragma once

#include "Core/System/Subsystem.hpp"
#include "Core/System/Macrosystem.hpp"
#include "Assets/AssetManager.hpp"
#include "Resources/Interfaces/IResourceLoader.hpp"
#include "Resources/Resource.hpp"
#include <unordered_map>
#include <filesystem>
#include <concepts>

class ResourceManager final : public Subsystem {
private:
    std::unordered_map<std::type_index, std::unique_ptr<IResourceLoader>> loaders_;
    AssetManager* asset_manager_ = nullptr;

public:
    /**
     * @brief Constructor
     */
    ResourceManager();

    /**
     * @brief Depencency resolution logic.
     */
    void resolveDependencies(Macrosystem* system) final;

    /**
     * @brief Adds a resource loader to the resource manager.
     * 
     * @param args... Constructor arguments for the desired loader.
     */
    template<typename ResourceLoader_t>
    requires std::is_base_of_v<IResourceLoader, ResourceLoader_t>
    ResourceLoader_t* addLoader();

    /**
     * @brief Load the desired resource.
     * 
     * @param local_path The path to the asset relative to the asset type folder.
     * @return The loaded asset.
     */
    template<typename Resource_t>
    requires std::is_base_of_v<Resource, Resource_t> || std::is_same_v<Resource, Resource_t>
    std::shared_ptr<Resource_t> load(const std::filesystem::path& local_path);

    /**
     * @brief Gets the asset manager used by this resource manager.
     * 
     * @return The asset manager used by this resource manager.
     */
    AssetManager* assetManager() const;
};

#include "Resources/ResourceManager.tpp"
