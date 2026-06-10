/*
    ShaderAssetLoader.hpp

    Declaration of a shader file loader.
*/

#pragma once

#include "Assets/AssetLoader.hpp"
#include "Assets/AssetLoaderContext.hpp"
#include "Assets/Types/ShaderAsset.hpp"
#include "Core/Handle.hpp"
#include <filesystem>
#include <memory>

class ShaderAssetLoader final : public AssetLoader<ShaderAsset> {
protected:
    /**
     * @brief Loads an image file from memory.
     * 
     * @param local_path The local path to the asset.
     */
    std::pair<Handle<ShaderAsset>, ShaderAsset*> loadFromFile(const std::filesystem::path& local_path) final;

public:
    /**
     * @brief Constructor.
     */
    ShaderAssetLoader(AssetLoaderContext& context);
};
