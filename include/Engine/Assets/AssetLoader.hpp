/*
    AssetLoader.hpp

    Declaration for an asset loader, in charge of loading and caching assets from system files.
*/

#pragma once

#include "Assets/Interfaces/IAssetLoader.hpp"
#include "Assets/AssetLoaderContext.hpp"
#include "Assets/AssetRecord.hpp"
#include "Assets/Asset.hpp"
#include "Containers/HandleBuffer.hpp"
#include "Core/Handle.hpp"
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

    // Asset management
    std::unordered_map<std::filesystem::path, AssetRecordHandle<Asset_t>> cache_;
    HandleBuffer<AssetRecord<Asset_t>> records_;
    HandleBuffer<Asset_t> assets_;

    // Context
    AssetLoaderContext& context_;
    
protected:
    /**
     * @brief Loads an asset from a specified file path.
     * 
     * @param local_path The local path to the asset.
     */
    virtual std::pair<Handle<Asset_t>, Asset_t*> loadFromFile(const std::filesystem::path& full_path) = 0;

    /**
     * @brief Creates a handle for the desired asset.
     * 
     * @param args... The constructor arguments for the asset.
     */
    template<typename... Args>
    std::pair<Handle<Asset_t>, Asset_t*> createHandle(Args&& ...args);

public:
    using AssetType = Asset_t;

    /**
     * @brief Constructor.
     * 
     * @param context The context for this asset loader.
     * @param extension_whitelist The complete list of file extensions supported for this loader.
     */
    AssetLoader(AssetLoaderContext& context, const std::vector<std::filesystem::path> extension_whitelist = {});
    
    /**
     * @brief Resolves an asset handle.
     * 
     * @return The resolved asset pointer.
     */
    Asset_t* resolve(AssetRecordHandle<Asset_t> handle);

    /**
     * @brief Fetches an asset handle for the desired asset.
     * 
     * @param local_path The local path to the asset.
     * @return A handle to the desired asset.
     */
    AssetRecordHandle<Asset_t> fetch(const std::filesystem::path& local_path);

    /**
     * @brief Gets whether this asset loader supports a file extension.
     * 
     * @param extension The file extension desired.
     * @return If this loader supports this file extension.
     */
    bool supports(const std::filesystem::path& extension) const;

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
