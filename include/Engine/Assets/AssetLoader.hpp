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
#include <vector>
#include <string>

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
class AssetLoader {
private:
    const std::vector<std::string> SUPPORTED_EXTENTIONS_;
    std::optional<std::filesystem::path> DEFAULT_ASSET_;
    std::unordered_map<std::filesystem::path, std::shared_ptr<Asset_t>> assets_;
    std::filesystem::path assets_directory_;

protected:
    /**
     * @brief Loads an asset from a specified file path.
     * 
     * @param assets_directory The directory containing all assets.
     * @param local_path Filename of the texture.
     */
    virtual std::shared_ptr<Asset_t> loadFromFile(const std::filesystem::path& local_path) = 0;

public:
    /**
     * @brief Constructor.
     * 
     * @param supported_extensions The supported file extensions for this loader.
     * @param default_asset The (optional) default asset for this loader.
     */
    AssetLoader(const std::vector<std::string> supported_extensions, std::optional<std::filesystem::path> default_asset = std::nullopt);

    /**
     * @brief Loads a texture from memory.
     * 
     * @param assets_directory The directory containing all assets.
     * @param local_path Filename of the texture.
     */
    std::shared_ptr<Asset_t> fetch(const std::filesystem::path& local_path);

    /**
     * @brief Sets the assets directory for this loader.
     * 
     * @param assets_directory The asset directory.
     */
    void setAssetsDirectory(const std::filesystem::path& assets_directory);

    /**
     * @brief Gets the assets directory for this loader.
     * 
     * @return The asset directory.
     */
    const std::filesystem::path& assetsDirectory() const;

    /**
     * @brief Gets the default asset path for this asset loader.
     * 
     * @return The default asset path for this loader.
     */
    std::optional<std::filesystem::path> defaultAsset() const;

    /**
     * @brief Gets whether this asset loader supports a file.
     * 
     * @param path The file path desired.
     * @return If this loader supports this file type.
     */
    bool supports(const std::filesystem::path& path) const;

    /**
     * @brief Destructor.
     */
    virtual ~AssetLoader() = default;
};

#include "Assets/AssetLoader.tpp"
