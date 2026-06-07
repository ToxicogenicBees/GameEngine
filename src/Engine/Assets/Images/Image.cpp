/*
    Image.cpp

    Implementation of an image storage class
*/

#include "Assets/Images/Image.hpp"

Image::Image(unsigned char* pixels, const Size& size)
    : PIXEL_DATA_(pixels, pixels + 4 * size.area()), SIZE_(size) {}

Image::Image(std::vector<unsigned char> pixels, const Size& size)
    : PIXEL_DATA_(pixels), SIZE_(size) {}

Color4 Image::colorAt(const Vector2i& pixel) const {
    return colorAt(pixel.x, pixel.y);
}

Color4 Image::colorAt(int x, int y) const {
    if (x < 0 || x >= SIZE_.width() || y < 0 || y >= SIZE_.height())
        throw std::out_of_range("Pixel coordinates are out of bounds");

    size_t index = (y * SIZE_.width() + x) * 4;
    return Color4(
        static_cast<uint8_t>(PIXEL_DATA_[index]),
        static_cast<uint8_t>(PIXEL_DATA_[index + 1]),
        static_cast<uint8_t>(PIXEL_DATA_[index + 2]),
        static_cast<uint8_t>(PIXEL_DATA_[index + 3])
    );
}

Color4 Image::averageColor() const {
    uint64_t r = 0, g = 0, b = 0, a = 0;
    for (auto& color : pixels()) {
        r += (uint64_t)(color.r);
        g += (uint64_t)(color.g);
        b += (uint64_t)(color.b);
        a += (uint64_t)(color.a);
    }

    auto total_pixels = SIZE_.area();
    return Color4(
        static_cast<uint8_t>(r / total_pixels),
        static_cast<uint8_t>(g / total_pixels),
        static_cast<uint8_t>(b / total_pixels),
        static_cast<uint8_t>(a / total_pixels)
    );
}

Image Image::toGrayscale() const {
    std::vector<unsigned char> grayscale_pixels = PIXEL_DATA_;
    for (size_t i = 0; i < grayscale_pixels.size(); i += 4) {
        uint8_t r = static_cast<uint8_t>(grayscale_pixels[i]);
        uint8_t g = static_cast<uint8_t>(grayscale_pixels[i + 1]);
        uint8_t b = static_cast<uint8_t>(grayscale_pixels[i + 2]);
        uint8_t a = static_cast<uint8_t>(grayscale_pixels[i + 3]);
        uint8_t gray = static_cast<uint8_t>(0.299 * r + 0.587 * g + 0.114 * b);
        grayscale_pixels[i] = gray;
        grayscale_pixels[i + 1] = gray;
        grayscale_pixels[i + 2] = gray;
        grayscale_pixels[i + 3] = a;
    }
    return Image(grayscale_pixels, SIZE_);
}

const unsigned char* Image::pixelData() const {
    return PIXEL_DATA_.begin().base();
}

std::vector<Color4> Image::pixels() const {
    std::vector<Color4> result;
    for (size_t i = 0; i < SIZE_.area(); ++i) {
        uint8_t r = PIXEL_DATA_[4*i];
        uint8_t g = PIXEL_DATA_[4*i + 1];
        uint8_t b = PIXEL_DATA_[4*i + 2];
        uint8_t a = PIXEL_DATA_[4*i + 3];
        result.push_back(Color4(r, g, b, a));
    }

    return result;
}

Size Image::size() const {
    return SIZE_;
}
