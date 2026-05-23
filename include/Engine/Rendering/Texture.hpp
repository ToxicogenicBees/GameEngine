/*
    Texture.hpp

    Declaration for a SDL3 + stbi texture class wrapper
*/

#pragma once

#include "Types/Vector2.hpp"
#include "Types/Color4.hpp"
#include "Types/Size.hpp"
#include "Assets/Asset.hpp"
#include <SDL3/SDL.h>
#include <filesystem>
#include <vector>

class Texture : public Asset {
private:
    SDL_Texture* texture_ = nullptr;
    std::string pixels_;
    Size size_;

protected:
    /**
     * @brief Gets the raw SDL_Texture pointer.
     * 
     * @return The raw SDL_Texture pointer.
     */
    SDL_Texture* raw() const;

public:
    friend class Renderer;

    /**
     * @brief Constructor
     * 
     * @param asset_path The full path to the asset file.
     */
    Texture(const std::filesystem::path& asset_path);

    /**
     * @brief Copy constructor (deleted)
     */
    Texture(const Texture&) = delete;

    /**
     * @brief Copy assignment operator (deleted)
     */
    Texture& operator=(const Texture&) = delete;

    /**
     * @brief Loads a texture from a file.
     * 
     * @param renderer The SDL_Renderer to create the texture with.
     * @param path The path to the texture file.
     * @return True if the texture was loaded successfully, false otherwise.
     */
    bool loadFromFile(SDL_Renderer* renderer, const std::filesystem::path& path);

    /**
     * @brief Gets the size of the texture.
     * 
     * @return The size of the texture.
     */
    Size size() const;

    /**
     * @brief Gets the width of the texture.
     * 
     * @return The width of the texture.
     */
    size_t width() const;

    /**
     * @brief Gets the height of the texture.
     * 
     * @return The height of the texture.
     */
    size_t height() const;

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
     * @brief Destructor
     */
    ~Texture();
};
