/*
    IAssetLoader.hpp

    An interface for an asset loader.
*/

#pragma once

#include <filesystem>
#include <typeindex>
#include <memory>

class IAssetLoader {
public:
    /**
     * @brief Loads an asset with an erased type.
     * 
     * @param local_path The local path to the asset.
     */
    virtual std::shared_ptr<void> loadErased(const std::filesystem::path& local_path) = 0;

    /**
     * @brief Get the asset type of this loader.
     * 
     * @return The asset type of this loader.
     */
    virtual std::type_index assetType() const = 0;

    /**
     * @brief Gets whether this asset loader supports a file extension.
     * 
     * @param extension The file extension desired.
     * @return If this loader supports this file extension.
     */
    virtual bool supports(const std::filesystem::path& extension) const = 0;

    /**
     * @brief Destructor.
     */
    virtual ~IAssetLoader() = default;
};