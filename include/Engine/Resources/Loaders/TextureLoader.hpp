/*
    TextureLoader.hpp

    Declaration of an SDL3 + stb_image texture loader
*/

#pragma once

#include "Resources/ResourceLoader.hpp"
#include "Resources/Types/Texture.hpp"
#include "Assets/Types/ImageAsset.hpp"
#include <memory>

class TextureLoader final : public ResourceLoader<ImageAsset, Texture> {
protected:
    /**
     * @brief Loads a texture from CPU memory to the GPU.
     * 
     * @param image The image asset being converted to a texture.
     */
    std::shared_ptr<Texture> loadFromAsset(std::shared_ptr<ImageAsset> image) final;

public:
    /**
     * @brief Constructor.
     */
    TextureLoader() = default;
};
