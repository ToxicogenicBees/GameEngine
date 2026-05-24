/*
    Texture.cpp

    Implementation for a SDL3 + stbi texture class wrapper
*/

#include "Rendering/Texture.hpp"

Texture::Texture(SDL_Texture* handle, const std::string& pixels, const Size& size)
    : handle_(handle), PIXELS_(pixels), SIZE_(size) {}

Size Texture::size() const {
    return SIZE_;
}

size_t Texture::width() const {
    return SIZE_.width;
}

size_t Texture::height() const {
    return SIZE_.height;
}

Color4 Texture::colorAt(const Vector2i& pixel) const {
    return colorAt(pixel.x, pixel.y);
}

Color4 Texture::colorAt(int x, int y) const {
    if (x < 0 || x >= SIZE_.width || y < 0 || y >= SIZE_.height)
        throw std::out_of_range("Pixel coordinates are out of bounds");

    size_t index = (y * SIZE_.width + x) * 4;
    return Color4(
        (uint8_t)(PIXELS_[index]),
        (uint8_t)(PIXELS_[index + 1]),
        (uint8_t)(PIXELS_[index + 2]),
        (uint8_t)(PIXELS_[index + 3])
    );
}

Color4 Texture::averageColor() const {
    uint64_t r = 0, g = 0, b = 0, a = 0;
    for (size_t i = 0; i < PIXELS_.size(); i += 4) {
        r += (uint64_t)(PIXELS_[i]);
        g += (uint64_t)(PIXELS_[i + 1]);
        b += (uint64_t)(PIXELS_[i + 2]);
        a += (uint64_t)(PIXELS_[i + 3]);
    }
    size_t total_pixels = PIXELS_.size() / 4;
    return Color4(
        static_cast<uint8_t>(r / total_pixels),
        static_cast<uint8_t>(g / total_pixels),
        static_cast<uint8_t>(b / total_pixels),
        static_cast<uint8_t>(a / total_pixels)
    );
}

SDL_Texture* Texture::raw() const {
    return handle_;
}

Texture::~Texture() {
    if (handle_) {
        SDL_DestroyTexture(handle_);
        handle_ = nullptr;
    }
}
