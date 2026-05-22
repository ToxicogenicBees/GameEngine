/*
    Texture.cpp

    Implementation for a SDL3 + stbi texture class wrapper
*/

#include "Rendering/Texture.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

/**
 * @brief Gets the raw SDL_Texture pointer.
 * 
 * @return The raw SDL_Texture pointer.
 */
SDL_Texture* Texture::raw() const {
    return texture_;
}

/**
 * @brief Constructor
 * 
 * @param asset_path The full path to the asset file.
 */
Texture::Texture(const std::filesystem::path& asset_path)
    : Asset(asset_path) {}

/**
 * @brief Loads a texture from a file.
 * 
 * @param renderer The SDL_Renderer to create the texture with.
 * @param path The path to the texture file.
 * @return True if the texture was loaded successfully, false otherwise.
 */
bool Texture::loadFromFile(SDL_Renderer* renderer, const std::filesystem::path& path) {
    int channels, width, height;

    unsigned char* data = stbi_load(
        path.string().c_str(),
        &width,
        &height,
        &channels,
        4
    );

    if (!data) {
        SDL_Log("stb_image failed: %s", stbi_failure_reason());
        return false;
    }

    pixels_.assign((char*)data, width * height * 4);

    SDL_Surface* surface = SDL_CreateSurfaceFrom(
        width,
        height,
        SDL_PIXELFORMAT_RGBA32,
        data,
        width * 4
    );

    if (!surface) {
        SDL_Log("SDL surface creation failed: %s", SDL_GetError());
        stbi_image_free(data);
        return false;
    }

    texture_ = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_DestroySurface(surface);
    stbi_image_free(data);

    if (!texture_) {
        SDL_Log("SDL texture creation failed: %s", SDL_GetError());
        return false;
    }

    size_ = Size((size_t)width, (size_t)height);

    return true;
}

/**
 * @brief Gets the size of the texture.
 * 
 * @return The size of the texture.
 */
Size Texture::size() const {
    return size_;
}

/**
 * @brief Gets the width of the texture.
 * 
 * @return The width of the texture.
 */
size_t Texture::width() const {
    return size_.width;
}

/**
 * @brief Gets the height of the texture.
 * 
 * @return The height of the texture.
 */
size_t Texture::height() const {
    return size_.height;
}

/**
 * @brief Gets the color of a specific pixel in the texture.
 * 
 * @param pixel The pixel coordinates to get the color of.
 * @return The color of the specified pixel.
 */
Color4 Texture::colorAt(const Vector2i& pixel) const {
    return colorAt(pixel.x, pixel.y);
}

/**
 * @brief Gets the color of a specific pixel in the texture.
 * 
 * @param x The x-coordinate of the pixel to get the color of.
 * @param y The y-coordinate of the pixel to get the color of.
 * @return The color of the specified pixel.
 */
Color4 Texture::colorAt(int x, int y) const {
    if (x < 0 || x >= size_.width || y < 0 || y >= size_.height)
        throw std::out_of_range("Pixel coordinates are out of bounds");

    size_t index = (y * size_.width + x) * 4;
    return Color4(
        (uint8_t)(pixels_[index]),
        (uint8_t)(pixels_[index + 1]),
        (uint8_t)(pixels_[index + 2]),
        (uint8_t)(pixels_[index + 3])
    );
}

/**
 * @brief Gets the average color of the texture.
 * 
 * @return The average color of the texture.
 */
Color4 Texture::averageColor() const {
    uint64_t r = 0, g = 0, b = 0, a = 0;
    for (size_t i = 0; i < pixels_.size(); i += 4) {
        r += (uint64_t)(pixels_[i]);
        g += (uint64_t)(pixels_[i + 1]);
        b += (uint64_t)(pixels_[i + 2]);
        a += (uint64_t)(pixels_[i + 3]);
    }
    size_t total_pixels = pixels_.size() / 4;
    return Color4(
        static_cast<uint8_t>(r / total_pixels),
        static_cast<uint8_t>(g / total_pixels),
        static_cast<uint8_t>(b / total_pixels),
        static_cast<uint8_t>(a / total_pixels)
    );
}

/**
 * @brief Destructor
 */
Texture::~Texture() {
    if (texture_) {
        SDL_DestroyTexture(texture_);
        texture_ = nullptr;
    }
}
