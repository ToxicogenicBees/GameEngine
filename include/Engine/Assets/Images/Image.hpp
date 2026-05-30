/*
    Image.hpp

    Declaration of an image storage class
*/

#pragma once

#include "Assets/Asset.hpp"
#include "Types/Color4.hpp"
#include "Math/Vector2.hpp"
#include "Types/Size.hpp"
#include <filesystem>
#include <string>

class Image : public Asset {
private:
    const std::string PIXELS_;
    const Size SIZE_;

public:
    /**
     * @brief Constructor.
     * 
     * @param path The file path of this asset.
     * @param pixels The pixels of the image in string format.
     * @param size The size of the image.
     */
    Image(const std::filesystem::path& path, const std::string& pixels, const Size& size);

    /**
     * @brief Gets the color of a specific pixel in the image.
     * 
     * @param pixel The pixel coordinates to get the color of.
     * @return The color of the specified pixel.
     */
    Color4 colorAt(const Vector2i& pixel) const;

    /**
     * @brief Gets the color of a specific pixel in the image.
     * 
     * @param x The x-coordinate of the pixel to get the color of.
     * @param y The y-coordinate of the pixel to get the color of.
     * @return The color of the specified pixel.
     */
    Color4 colorAt(int x, int y) const;

    /**
     * @brief Gets the average color of the image.
     * 
     * @return The average color of the image.
     */
    Color4 averageColor() const;

    /**
     * @brief Gets the pixel content of the image.
     * 
     * @return The pixel content of the image.
     */
    std::string pixels() const;

    /**
     * @brief Gets the size of the image.
     * 
     * @return The size of the image.
     */
    Size size() const;
};
