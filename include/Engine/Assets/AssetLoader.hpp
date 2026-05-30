/*
    AssetLoader.hpp

    Declaration for an asset loader, in charge of loading and caching assets from system files.
*/

#pragma once

#include "Assets/Asset.hpp"
#include <unordered_map>
#include <filesystem>
#include <concepts>
#include <memory>

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
class AssetLoader {
private:
    const std::filesystem::path SUBFOLDER_;
    std::unordered_map<std::filesystem::path, std::shared_ptr<Asset_t>> assets_;

protected:
    /**
     * @brief Loads an asset from a specified file path.
     * 
     * @param path The path to the desired file.
     */
    virtual std::shared_ptr<Asset_t> loadFromFile(const std::filesystem::path& path) = 0;

public:
    /**
     * @brief Constructor.
     * 
     * @param subfolder The subfolder in the assets folder this loader searches in.
     */
    AssetLoader(const std::filesystem::path& subfolder);

    /**
     * @brief Loads a texture from memory.
     * 
     * @param path Filename of the texture.
     */
    std::shared_ptr<Asset_t> fetch(const std::filesystem::path& path);

    /**
     * @brief Gets the subfolder for this asset loader.
     * 
     * @return The subfolder for this asset loader.
     */
    std::filesystem::path subfolder() const;

    /**
     * @brief Destructor.
     */
    virtual ~AssetLoader() = default;
};

#include "Assets/AssetLoader.tpp"
