/*
    Viewport.cpp

    Implementation of a simple class containing viewport data
*/

#include "foundation/utility/fp_type.hpp"
#include "rendering/Viewport.hpp"

namespace toxico {
    Viewport::Viewport(Size size)
        : size_(size) {}

    Vector2 Viewport::center() const {
        return {
            fp_type{0.5} * size_.width,
            fp_type{0.5} * size_.height
        };
    }

    Size Viewport::size() const{
        return size_;
    }
}
