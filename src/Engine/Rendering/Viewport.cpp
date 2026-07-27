/*
    Viewport.cpp

    Implementation of a simple class containing viewport data
*/

#include "Rendering/Viewport.hpp"

namespace toxico {
    Viewport::Viewport(Size size)
        : size_(size) {}

    Vector2 Viewport::center() const {
        return {0.5 * size_.width(), 0.5 * size_.height()};
    }

    Size Viewport::size() const{
        return size_;
    }
}
