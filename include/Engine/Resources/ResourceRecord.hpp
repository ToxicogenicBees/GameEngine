/*
    ResourceRecord.hpp

    Declaration for a resource manager record
*/

#pragma once

#include "Core/Handle.hpp"
#include "Resources/Resource.hpp"
#include <filesystem>
#include <concepts>

template<typename Resource_t>
requires std::is_base_of_v<Resource, Resource_t>
class ResourceRecord {
private:
    const std::filesystem::path PATH_;
    Handle<Resource_t> handle_;
    bool loaded_ = false;

public:
    /**
     * @brief Constructor.
     * 
     * @param local_path The local path to the resource.
     * @param handle The handle for the resource.
     */
    ResourceRecord(const std::filesystem::path& path, Handle<Resource_t> handle);

    /**
     * @brief Constructor.
     */
    ResourceRecord() = default;

    /**
     * @brief Loads the desired handle into the record.
     * 
     * @param handle The handle being loaded.
     */
    void load(Handle<Resource_t> handle);

    /**
     * @brief Marks the resource as unloaded.
     */
    void unload();

    /**
     * @brief Gets the handle for this record.
     * 
     * @return The handle for this record.
     */
    Handle<Resource_t> handle();

    /**
     * @brief Gets the path for this record.
     * 
     * @return The path for this record.
     */
    const std::filesystem::path& path() const;

    /**
     * @brief Gets if the desired resource is loaded.
     * 
     * @return If the resource is loaded.
     */
    bool isLoaded() const;
};

template<typename Resource_t>
requires std::is_base_of_v<Resource, Resource_t>
using ResourceRecordHandle = Handle<ResourceRecord<Resource_t>>;

#include "Resources/ResourceRecord.tpp"
