/*
    Asset.hpp

    Declaration for an abstract asset class
*/

#pragma once

#include <filesystem>

class Asset {
protected:
    const std::filesystem::path PATH_;

public:
    /**
     * @brief Constructor
     * 
     * @param asset_path The full path to the asset file.
     */
    Asset(const std::filesystem::path& asset_path);

    /**
     * @brief Gets the path to the asset file.
     * 
     * @return The path to the asset file.
     */
    const std::filesystem::path& path() const noexcept;

    /**
     * @brief Destructor
     */
    virtual ~Asset() = default;
};
