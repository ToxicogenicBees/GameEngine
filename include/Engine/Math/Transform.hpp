/*
    Transform.hpp

    A simple struct containing transformation info
*/

#pragma once

#include "Math/Vector2.hpp"

struct Transform {
    Vector2 position = Vector2::zero();
    Vector2 scale = Vector2::one();
    double rotation = 0.0;
};
