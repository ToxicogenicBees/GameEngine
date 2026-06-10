/*
    ResourceLoaderContext.hpp

    A simple struct containing context for resource loaders.
*/

#pragma once

#include <filesystem>

class ResourceManager;  // forward declaration
class AssetManager;     // forward declaration

struct ResourceLoaderContext {
    ResourceManager& resources;
    AssetManager* asset_manager;
};
