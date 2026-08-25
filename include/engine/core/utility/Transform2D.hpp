/*
    Transform2D.hpp

    Implementation of a 2D transformation info component.
*/

#pragma once

#include "foundation/utility/StagedValue.hpp"
#include "foundation/math/Vector.hpp"

namespace toxico {
    struct Transform2D {
        StagedValue<Vector2> position{Vector2::zero()};
        StagedValue<Vector2> scale{Vector2::one()};
        StagedValue<double> rotation{0.0};

        /**
         * @brief Commits the transform.
         */
        void commit();
    };
}
