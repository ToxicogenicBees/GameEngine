/*
    Asset.cpp

    Implementation of an asset class, containing data loaded in from files.
*/

#include "Assets/Asset.hpp"

Asset::Asset(const std::filesystem::path& path)
    : PATH_(path) {}

std::filesystem::path Asset::path() const {
    return PATH_;
}
