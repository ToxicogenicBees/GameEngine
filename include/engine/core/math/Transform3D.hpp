/*
    Transform3D.hpp

    Declaration of a struct containing 3D transformation info
*/

#pragma once

#include "foundation/utility/StagedValue.hpp"
#include "core/math/Quaternion.hpp"
#include "core/math/Vector.hpp"

namespace toxico {
    struct Transform3D {
        StagedValue<Vector3> position{Vector3::zero()};
        StagedValue<Vector3> scale{Vector3::one()};
        StagedValue<Quaternion> rotation{Quaternion(0, 0, 0, 0)};

        /**
         * @brief Commits the transform.
         */
        void commit();
    };
}
