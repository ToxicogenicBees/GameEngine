/*
    FileLoader.hpp

    Declaration of a raw text file loader.
*/

#pragma once

#include "Assets/AssetLoader.hpp"
#include "Assets/AssetLoaderContext.hpp"
#include "Assets/Types/File.hpp"
#include "Core/Handle.hpp"
#include <filesystem>
#include <memory>

class FileLoader final : public AssetLoader<File> {
protected:
    /**
     * @brief Loads an image file from memory.
     * 
     * @param local_path The local path to the asset.
     */
    std::pair<Handle<File>, File*> loadFromFile(const std::filesystem::path& local_path) final;

public:
    /**
     * @brief Constructor.
     */
    FileLoader(AssetLoaderContext& context);
};
