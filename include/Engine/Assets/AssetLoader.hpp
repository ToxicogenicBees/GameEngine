/*
    AssetLoader.hpp

    Declaration for an asset loader, in charge of loading and caching assets from system files.
*/

#pragma once

#include "Assets/Asset.hpp"
#include <unordered_map>
#include <filesystem>
#include <optional>
#include <concepts>
#include <memory>

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
class AssetLoader {
private:
    const std::filesystem::path SUBFOLDER_;
    std::optional<std::filesystem::path> DEFAULT_ASSET_;
    std::unordered_map<std::filesystem::path, std::shared_ptr<Asset_t>> assets_;

protected:
    /**
     * @brief Loads an asset from a specified file path.
     * 
     * @param assets_directory The directory containing all assets.
     * @param local_path Filename of the texture.
     */
    virtual std::shared_ptr<Asset_t> loadFromFile(const std::filesystem::path& assets_directory, const std::filesystem::path& local_path) = 0;

public:
    /**
     * @brief Constructor.
     * 
     * @param subfolder The subfolder in the assets folder this loader searches in.
     * @param default_asset The (optional) default asset for this loader.
     */
    AssetLoader(const std::filesystem::path& subfolder, std::optional<std::filesystem::path> default_asset = std::nullopt);

    /**
     * @brief Loads a texture from memory.
     * 
     * @param assets_directory The directory containing all assets.
     * @param local_path Filename of the texture.
     */
    std::shared_ptr<Asset_t> fetch(const std::filesystem::path& assets_directory, const std::filesystem::path& local_path);

    /**
     * @brief Gets the subfolder for this asset loader.
     * 
     * @return The subfolder for this asset loader.
     */
    std::filesystem::path subfolder() const;

    /**
     * @brief Gets the default asset path for this asset loader.
     * 
     * @return The default asset path for this loader.
     */
    std::optional<std::filesystem::path> defaultAsset() const;

    /**
     * @brief Destructor.
     */
    virtual ~AssetLoader() = default;
};

#include "Assets/AssetLoader.tpp"
