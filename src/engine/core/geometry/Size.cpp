/*
    Size.hpp

    Implementation for the Size class
*/

#include "core/geometry/Size.hpp"

namespace toxico {
    Size::Size(size_t width, size_t height)
        : width(width), height(height) {}

    size_t Size::area() const {
        return width * height;
    }

    bool Size::operator==(Size size) const {
        return width == size.width
            && height == size.height;
    }

    std::ostream& operator<<(std::ostream& o, Size size) {
        o << "(" << size.width << "x" << size.height << ")";
        return o;
    }
}
