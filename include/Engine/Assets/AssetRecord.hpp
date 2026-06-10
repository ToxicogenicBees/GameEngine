/*
    AssetRecord.hpp

    Declaration for an asset manager record
*/

#pragma once

#include "Core/Handle.hpp"
#include "Assets/Asset.hpp"
#include <filesystem>
#include <concepts>

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
class AssetRecord {
private:
    const std::filesystem::path PATH_;
    Handle<Asset_t> handle_;
    bool loaded_ = false;

public:
    /**
     * @brief Constructor.
     * 
     * @param local_path The local path to the asset.
     * @param handle The handle for the asset.
     */
    AssetRecord(const std::filesystem::path& path, Handle<Asset_t> handle);

    /**
     * @brief Constructor.
     */
    AssetRecord() = default;

    /**
     * @brief Loads the desired handle into the record.
     * 
     * @param handle The handle being loaded.
     */
    void load(Handle<Asset_t> handle);

    /**
     * @brief Marks the asset as unloaded.
     */
    void unload();

    /**
     * @brief Gets the handle for this record.
     * 
     * @return The handle for this record.
     */
    Handle<Asset_t> handle();

    /**
     * @brief Gets the path for this record.
     * 
     * @return The path for this record.
     */
    const std::filesystem::path& path() const;

    /**
     * @brief Gets if the desired asset is loaded.
     * 
     * @return If the asset is loaded.
     */
    bool isLoaded() const;
};

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
using AssetRecordHandle = Handle<AssetRecord<Asset_t>>;

#include "Assets/AssetRecord.tpp"
