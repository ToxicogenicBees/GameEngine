/*
    Size.hpp

    Implementation for the Size class
*/

#include "Types/Size.hpp"

Size::Size(double width, double height)
    : width_(width), height_(height) {}

void Size::setSize(double width, double height) {
    width_ = width;
    height_ = height;
}

double Size::width() const {
    return width_;
}

void Size::setWidth(double width) {
    width_ = width;
}

double Size::height() const {
    return height_;
}

void Size::setHeight(double height) {
    height_ = height;
}

double Size::area() const {
    return width_ * height_;
}
