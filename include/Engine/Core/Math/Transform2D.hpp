/*
    Transform2D.hpp

    Declaration of a struct containing 2D transformation info
*/

#pragma once

#include "Core/Math/Vector2.hpp"

namespace toxico {
    struct Transform_ {
        Vector2 position = Vector2::zero();
        Vector2 scale = Vector2::one();
        double rotation = 0.0;
    };
}
