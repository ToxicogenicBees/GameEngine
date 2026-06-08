/*
    ResourceManager.hpp

    Declaration for the resource manager, which loads and manages game resources such as textures and audio
*/

#pragma once

#include "Core/System/Subsystem.hpp"
#include "Core/System/Macrosystem.hpp"
#include "Assets/AssetManager.hpp"
#include "Resources/Textures/TextureLoader.hpp"
#include "Resources/Textures/Texture.hpp"
#include <unordered_map>
#include <filesystem>
#include <concepts>
#include <mutex>

class ResourceManager final : public Subsystem {
private:
    AssetManager* asset_manager_ = nullptr;

    TextureLoader texture_loader_;

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
     * @brief Load the desired texture
     * 
     * @param local_path The path to the asset relative to the asset type folder.
     * @return The loaded asset.
     */
    std::shared_ptr<Texture> loadTexture(const std::filesystem::path& local_path);

    /**
     * @brief Gets the asset manager used by this resource manager.
     * 
     * @return The asset manager used by this resource manager.
     */
    AssetManager* assetManager() const;
};
