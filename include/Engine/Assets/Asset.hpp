/*
    Asset.hpp

    Declaration of an asset class, containing data loaded in from files.
*/

#pragma once

#include <filesystem>

class Asset {
private:
    std::filesystem::path PATH_;

public:
    /**
     * @brief Constructor.
     * 
     * @param path The file path of this asset
     */
    Asset(const std::filesystem::path& path);

    /**
     * @brief Copy constructor (deleted)
     */
    Asset(const Asset&) = delete;

    /**
     * @brief Gets the file path of the asset.
     * 
     * @return The file path of the asset.
     */
    std::filesystem::path path() const;

    /**
     * @brief Destructor.
     */
    virtual ~Asset() = default;
};
