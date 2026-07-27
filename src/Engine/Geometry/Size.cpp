/*
    Size.hpp

    Implementation for the Size class
*/

#include "Geometry/Size.hpp"

namespace toxico {
    Size::Size(std::size_t width, std::size_t height)
        : width_(width), height_(height) {}

    void Size::setSize(std::size_t width, std::size_t height) {
        width_ = width;
        height_ = height;
    }

    std::size_t Size::width() const {
        return width_;
    }

    void Size::setWidth(std::size_t width) {
        width_ = width;
    }

    std::size_t Size::height() const {
        return height_;
    }

    void Size::setHeight(std::size_t height) {
        height_ = height;
    }

    std::size_t Size::area() const {
        return width_ * height_;
    }

    bool Size::operator==(Size size) const {
        return width_ == size.width_
            && height_ == size.height_;
    }

    std::ostream& operator<<(std::ostream& o, Size size) {
        o << "(" << size.width() << "x" << size.height() << ")";
        return o;
    }
}
