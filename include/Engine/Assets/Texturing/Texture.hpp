/*
    Texture.hpp

    Declaration for a SDL3 + stbi texture class wrapper
*/

#pragma once

#include "Assets/Asset.hpp"
#include "Types/Vector2.hpp"
#include "Types/Color4.hpp"
#include "Types/Size.hpp"
#include <SDL3/SDL.h>
#include <filesystem>
#include <vector>

class Texture : public Asset {
private:
    SDL_Texture* handle_;
    const std::string PIXELS_;
    const Size SIZE_;

public:
    /**
     * @brief Constructor
     * 
     * @param handle Pointer to the constructed SDL_Texture handler for this texture
     * @param pixels The raw pixel colors of the texture
     * @param size The size of the texture
     */
    Texture(const std::filesystem::path& path, SDL_Texture* handle, const std::string& pixels, const Size& size);

    /**
     * @brief Copy assignment operator (deleted)
     */
    Texture& operator=(const Texture&) = delete;

    /**
     * @brief Gets the size of the texture.
     * 
     * @return The size of the texture.
     */
    Size size() const;

    /**
     * @brief Gets the color of a specific pixel in the texture.
     * 
     * @param pixel The pixel coordinates to get the color of.
     * @return The color of the specified pixel.
     */
    Color4 colorAt(const Vector2i& pixel) const;

    /**
     * @brief Gets the color of a specific pixel in the texture.
     * 
     * @param x The x-coordinate of the pixel to get the color of.
     * @param y The y-coordinate of the pixel to get the color of.
     * @return The color of the specified pixel.
     */
    Color4 colorAt(int x, int y) const;

    /**
     * @brief Gets the average color of the texture.
     * 
     * @return The average color of the texture.
     */
    Color4 averageColor() const;

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
