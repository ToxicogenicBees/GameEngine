/*
    TextureLoader.hpp

    Declaration of an SDL3 + stb_image texture loader
*/

#pragma once

#include "Resources/ResourceLoader.hpp"
#include "Assets/Images/ImageLoader.hpp"
#include "Assets/Images/Image.hpp"
#include "Resources/Textures/Texture.hpp"
#include <SDL3/SDL.h>
#include <filesystem>
#include <memory>

class TextureLoader : public ResourceLoader<Texture> {
protected:
    /**
     * @brief Loads a texture from memory
     * 
     * @param path Filename of the texture
     */
    std::shared_ptr<Texture> loadFromAsset(const std::filesystem::path& path) override;

public:
    /**
     * @brief Constructor.
     * 
     * @param subfolder The subfolder in the assets folder this loader searches in.
     */
    TextureLoader(AssetManager& asset_manager);
};
