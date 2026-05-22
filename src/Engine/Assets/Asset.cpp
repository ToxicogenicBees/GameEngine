/*
    Asset.cpp

    Implementation for an abstract asset class
*/

#include "Assets/Asset.hpp"

/**
 * @brief Constructor
 * 
 * @param asset_path The full path to the asset file.
 */
Asset::Asset(const std::filesystem::path& asset_path)
    : PATH_(asset_path) {}

/**
 * @brief Gets the path to the asset file.
 * 
 * @return The path to the asset file.
 */
const std::filesystem::path& Asset::path() const noexcept {
    return PATH_;
}
