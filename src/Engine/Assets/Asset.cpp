/*
    Asset.cpp

    Implementation for an abstract asset class
*/

#include "Assets/Asset.hpp"

Asset::Asset(const std::filesystem::path& asset_path)
    : PATH_(asset_path) {}

const std::filesystem::path& Asset::path() const noexcept {
    return PATH_;
}
