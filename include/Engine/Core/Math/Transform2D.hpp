/*
    Transform2D.hpp

    Declaration of a struct containing 2D transformation info
*/

#pragma once

#include "Foundation/StagedValue.hpp"
#include "Core/Math/Vector2.hpp"

namespace toxico {
    struct Transform2D {
        StagedValue<Vector2> position = Vector2::zero();
        StagedValue<Vector2> scale = Vector2::one();
        StagedValue<double> rotation = 0.0;
    };
}
