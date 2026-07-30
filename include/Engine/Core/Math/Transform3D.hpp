/*
    Transform3D.hpp

    Declaration of a struct containing 3D transformation info
*/

#pragma once

#include "Core/Math/Quaternion.hpp"
#include "Core/Math/Vector2.hpp"
#include "Core/Math/Vector3.hpp"

namespace toxico {
    struct Transform3D {
        Vector3 position = Vector3::zero();
        Vector3 scale = Vector3::one();
        Quaternion rotation = Quaternion(0, 0, 0, 0);
    };
}
