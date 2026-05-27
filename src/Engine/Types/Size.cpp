/*
    Size.hpp

    Implementation for the Size class
*/

#include "Types/Size.hpp"

Size::Size(size_t width, size_t height)
    : width_(width), height_(height) {}

void Size::setSize(size_t width, size_t height) {
    width_ = width;
    height_ = height;
}

size_t Size::width() const {
    return width_;
}

void Size::setWidth(size_t width) {
    width_ = width;
}

size_t Size::height() const {
    return height_;
}

void Size::setHeight(size_t height) {
    height_ = height;
}

size_t Size::area() const {
    return width_ * height_;
}

bool Size::operator==(const Size& size) const {
    return width_ == size.width_
        && height_ == size.height_;
}
