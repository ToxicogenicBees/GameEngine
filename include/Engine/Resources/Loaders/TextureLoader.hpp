/*
    TextureLoader.hpp

    Declaration of an SDL3 + stb_image texture loader
*/

#pragma once

#include "Resources/ResourceLoader.hpp"
#include "Resources/ResourceLoaderContext.hpp"
#include "Resources/Types/Texture.hpp"
#include "Assets/Types/Image.hpp"
#include "Core/Handle.hpp"
#include <memory>

class TextureLoader final : public ResourceLoader<Texture> {
protected:
    /**
     * @brief Loads a texture from CPU memory to the GPU.
     * 
     * @param image The image being converted to a texture.
     */
    std::pair<Handle<Texture>, Texture*> loadFromAsset(Texture::AssetType* image) final;

public:
    /**
     * @brief Constructor.
     */
    TextureLoader(ResourceLoaderContext& context);
};
