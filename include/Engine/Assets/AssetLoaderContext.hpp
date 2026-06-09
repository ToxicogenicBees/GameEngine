/*
    AssetLoaderContext.hpp

    A simple struct containing context for asset loaders.
*/

#pragma once

#include <filesystem>

class AssetManager; // forward declaration

struct AssetLoaderContext {
    AssetManager& assets;
    std::filesystem::path& assets_directory;
};
