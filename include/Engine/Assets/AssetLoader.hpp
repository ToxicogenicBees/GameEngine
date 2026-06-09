/*
    AssetLoader.hpp

    Declaration for an asset loader, in charge of loading and caching assets from system files.
*/

#pragma once

#include "Assets/Interfaces/IAssetLoader.hpp"
#include "Assets/AssetLoaderContext.hpp"
#include "Assets/Asset.hpp"
#include <unordered_map>
#include <filesystem>
#include <optional>
#include <concepts>
#include <memory>
#include <vector>

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
class AssetLoader : public IAssetLoader {
private:
    const std::vector<std::filesystem::path> EXTENSION_WHITELIST_;
    std::optional<std::filesystem::path> DEFAULT_ASSET_;

    std::unordered_map<std::filesystem::path, std::shared_ptr<Asset_t>> assets_;
    AssetLoaderContext& context_;

protected:
    /**
     * @brief Loads an asset from a specified file path.
     * 
     * @param local_path The local path to the asset.
     */
    virtual std::shared_ptr<Asset_t> loadFromFile(const std::filesystem::path& full_path) = 0;

public:
    using AssetType = Asset_t;

    /**
     * @brief Constructor.
     * 
     * @param extension_whitelist The complete list of file extensions supported for this loader.
     * @param default_asset The (optional) default asset for this loader.
     */
    AssetLoader(AssetLoaderContext& context, const std::vector<std::filesystem::path> extension_whitelist = {}, std::optional<std::filesystem::path> default_asset = std::nullopt);

    /**
     * @brief Loads an asset with an erased type.
     * 
     * @param local_path The local path to the asset.
     */
    std::shared_ptr<void> loadErased(const std::filesystem::path& local_path) final;

    /**
     * @brief Gets the default asset path for this asset loader.
     * 
     * @return The default asset path for this loader.
     */
    std::optional<std::filesystem::path> defaultAsset() const;

    /**
     * @brief Get the asset type of this loader.
     * 
     * @return The asset type of this loader.
     */
    std::type_index assetType() const final;

    /**
     * @brief Gets whether this asset loader supports a file extension.
     * 
     * @param extension The file extension desired.
     * @return If this loader supports this file extension.
     */
    bool supports(const std::filesystem::path& extension) const final;

    /**
     * @brief Gets this loader's context.
     * 
     * @return The loader's context.
     */
    AssetLoaderContext& context();

    /**
     * @brief Destructor.
     */
    virtual ~AssetLoader() = default;
};

#include "Assets/AssetLoader.tpp"
