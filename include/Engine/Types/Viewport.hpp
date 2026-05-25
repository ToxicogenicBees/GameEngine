/*
    Viewport.hpp

    Declaration of a simple class containing viewport data
*/

#pragma once

#include "Types/Vector2.hpp"
#include "Types/Size.hpp"

class Viewport {
private:
    Size size_;

public:
    /**
     * @brief Constructor
     * 
     * @param size The size of the viewport
     */
    Viewport(const Size& size = {0.0, 0.0});

    Vector2 center() const;

    Size size() const;
};
