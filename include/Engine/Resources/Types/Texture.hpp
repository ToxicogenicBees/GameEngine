/*
    Texture.hpp

    Declaration for a SDL3 + stbi texture class wrapper
*/

#pragma once

#include "Resources/Resource.hpp"
#include "Assets/Types/Image.hpp"
#include "Resources/ResourceRecord.hpp"
#include "Core/Handle.hpp"
#include "Geometry/Size.hpp"
#include <SDL3/SDL.h>

class Texture : public Resource {
private:
    SDL_Texture* handle_;
    const Size SIZE_;

public:
    using AssetType = Image;

    /**
     * @brief Constructor
     * 
     * @param handle Pointer to the constructed SDL_Texture handler for this texture
     * @param size The size of the texture
     */
    Texture(SDL_Texture* handle, Size size);

    /**
     * @brief Gets the size of the texture.
     * 
     * @return The size of the texture.
     */
    Size size() const;

    /**
     * @brief Gets the raw SDL_Texture pointer.
     * 
     * @return The raw SDL_Texture pointer.
     */
    SDL_Texture* raw() const;

    /**
     * @brief Destructor
     */
    ~Texture();
};

using TextureHandle = Handle<ResourceRecord<Texture>>;
