/*
    ShaderAssetLoader.cpp

    Implementation of a shader file loader.
*/

#include "Assets/Loaders/ShaderAssetLoader.hpp"
#include "Assets/AssetManager.hpp"
#include "Assets/Types/File.hpp"
#include <unordered_map>
#include <sstream>

namespace {
    void trim(std::string& str) {
        std::string blacklist = " \t\r\n";

        std::erase_if(str, [blacklist](char c) {
            return blacklist.find(c, 0) != std::string::npos;
        });
    }

    std::unordered_map<std::string, std::string> parseKeyValueFile(const std::string& text) {
        std::unordered_map<std::string, std::string> result;

        std::istringstream stream(text);
        std::string line;

        while (std::getline(stream, line)) {
            if (line.empty() || line[0] == '#')
                continue;

            auto pos = line.find('=');
            if (pos == std::string::npos)
                continue;

            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);

            trim(key);
            trim(value);

            result[key] = value;
        }

        return result;
    }
}

std::shared_ptr<ShaderAsset> ShaderAssetLoader::loadFromFile(const std::filesystem::path& local_path) {
    // Loads a file
    auto load = [this](const std::filesystem::path& path) {
        return context().assets.load<File>(path);
    };

    // Casts a file's byte data to a string
    auto string_content = [](std::shared_ptr<File> file) {
        auto content = file->content();
        return std::string(reinterpret_cast<const char*>(content.data()), content.size());
    };

    // Parse shader file
    auto data = parseKeyValueFile(string_content(load(local_path)));

    // Validate that vertex and fragment paths were defined
    auto vert_iter = data.find("vertex");
    auto frag_iter = data.find("fragment");
    if (vert_iter == data.end() || frag_iter == data.end()) {
        ENGINE_ERROR(ASSET, "Missing vertex/fragment in shader file");
        return nullptr;
    }

    // Fetch shader data
    auto vert_data = load(vert_iter->second);
    auto frag_data = load(frag_iter->second);

    // Return shader asset
    return std::make_shared<ShaderAsset>(vert_data, frag_data);
}

ShaderAssetLoader::ShaderAssetLoader(AssetLoaderContext& context)
    : AssetLoader<ShaderAsset>(context, {".shader"}, std::nullopt) {}
