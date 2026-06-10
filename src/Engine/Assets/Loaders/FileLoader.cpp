/*
    FileLoader.cpp

    Implementation of a raw text file loader.
*/

#include "Assets/Loaders/FileLoader.hpp"
#include "Logging/Logger.hpp"
#include <fstream>
#include <format>

std::pair<Handle<File>, File*> FileLoader::loadFromFile(const std::filesystem::path& local_path) {
    // Fetch full path
    auto full_path = context().assets_directory / local_path;

    // Open input file stream
    std::ifstream file(full_path.c_str(), std::ios::binary);
    if (!file.is_open()) {
        ENGINE_ERROR(ASSET, std::format(
            "Failed to open file \"{}\"",
            local_path.string()
        ));
        return {};
    }

    // Get file size
    file.seekg(0, std::ios::end);
    auto file_size = file.tellg();
    file.seekg(0, std::ios::beg);
    if (file_size < 0) {
        ENGINE_ERROR(ASSET, std::format(
            "Failed to read size of file \"{}\"",
            local_path.string()
        ));
        return {};
    }

    // Read file contents
    std::vector<std::byte> buffer(static_cast<size_t>(file_size));
    file.read(reinterpret_cast<char*>(buffer.data()), buffer.size());

    // Validate size
    if (static_cast<size_t>(file.gcount()) != buffer.size()) {
        ENGINE_ERROR(ASSET, std::format(
            "Failed to read entire file \"{}\"",
            local_path.string()
        ));
        return {};
    }

    // Create file asset
    return createHandle(std::move(buffer));
}

FileLoader::FileLoader(AssetLoaderContext& context)
    : AssetLoader<File>(context) {}
