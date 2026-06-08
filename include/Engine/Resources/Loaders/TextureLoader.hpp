/*
    TextureLoader.hpp

    Declaration of an SDL3 + stb_image texture loader
*/

#pragma once

#include "Resources/ResourceLoader.hpp"
#include "Resources/Types/Texture.hpp"
#include "Assets/Types/ImageAsset.hpp"
#include "Assets/AssetManager.hpp"
#include <SDL3/SDL.h>
#include <filesystem>
#include <memory>

class TextureLoader final : public ResourceLoader<ImageAsset, Texture> {
protected:
    /**
     * @brief Loads a texture from memory
     * 
     * @param path Filename of the texture
     */
    std::shared_ptr<Texture> loadFromAsset(std::shared_ptr<ImageAsset> image) override;

public:
    /**
     * @brief Constructor.
     */
    TextureLoader() = default;
};
