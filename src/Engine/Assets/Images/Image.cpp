/*
    Image.cpp

    Implementation of an image storage class
*/

#include "Assets/Images/Image.hpp"

Image::Image(const std::filesystem::path& path, const std::string& pixels, const Size& size)
    : Asset(path), PIXELS_(pixels), SIZE_(size) {}

Color4 Image::colorAt(const Vector2i& pixel) const {
    return colorAt(pixel.x, pixel.y);
}

Color4 Image::colorAt(int x, int y) const {
    if (x < 0 || x >= SIZE_.width() || y < 0 || y >= SIZE_.height())
        throw std::out_of_range("Pixel coordinates are out of bounds");

    size_t index = (y * SIZE_.width() + x) * 4;
    return Color4(
        (uint8_t)(PIXELS_[index]),
        (uint8_t)(PIXELS_[index + 1]),
        (uint8_t)(PIXELS_[index + 2]),
        (uint8_t)(PIXELS_[index + 3])
    );
}

Color4 Image::averageColor() const {
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

Image Image::toGrayscale() const {
    std::string grayscale_pixels = PIXELS_;
    for (size_t i = 0; i < grayscale_pixels.size(); i += 4) {
        uint8_t r = (uint8_t)(grayscale_pixels[i]);
        uint8_t g = (uint8_t)(grayscale_pixels[i + 1]);
        uint8_t b = (uint8_t)(grayscale_pixels[i + 2]);
        uint8_t a = (uint8_t)(grayscale_pixels[i + 3]);
        uint8_t gray = static_cast<uint8_t>(0.299 * r + 0.587 * g + 0.114 * b);
        grayscale_pixels[i] = gray;
        grayscale_pixels[i + 1] = gray;
        grayscale_pixels[i + 2] = gray;
        grayscale_pixels[i + 3] = a;
    }
    return Image(path(), grayscale_pixels, SIZE_);
}
std::string Image::pixels() const {
    return PIXELS_;
}

Size Image::size() const {
    return SIZE_;
}
