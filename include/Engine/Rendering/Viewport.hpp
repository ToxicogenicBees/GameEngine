/*
    Viewport.hpp

    Declaration of a simple class containing viewport data
*/

#pragma once

#include "Math/Vector2.hpp"
#include "Geometry/Size.hpp"

class Viewport {
private:
    Size size_;

public:
    /**
     * @brief Constructor.
     * 
     * @param size The size of the viewport.
     */
    Viewport(const Size& size = {0, 0});

    /**
     * @brief Gets the center point of the viewport.
     * 
     * @return The center point of the viewport.
     */
    Vector2 center() const;

    /**
     * @brief Gets the size of the viewport.
     * 
     * @return The size of the viewport.
     */
    Size size() const;
};
