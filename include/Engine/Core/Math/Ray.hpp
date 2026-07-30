/*
    Ray.hpp

    Declaration of a simple ray class.
*/

#pragma once

#include "Core/Math/Vector2.hpp"
#include "Core/Math/Vector3.hpp"

namespace toxico {
    template<typename Vector>
    struct Ray_;

    using Ray2 = Ray_<Vector2d>;
    using Ray3 = Ray_<Vector3d>;

    template<typename Vector>
    struct Ray_ {
        Vector direction{Vector::zero()};
        Vector origin{Vector::zero()};

        /**
         * @brief Constructor.
         * 
         * @param origin The origin of the ray.
         * @param direction The direction of the ray.
         */
        Ray_(Vector origin, Vector direction);

        /**
         * @brief Constructor.
         *        Assumes the ray origin is at the world origin.
         * 
         * @param direction The direction of the ray.
         */
        Ray_(Vector direction);

        /**
         * @brief Constructor.
         */
        Ray_() = default;

        /**
         * @brief Gets the length of the ray.
         * 
         * @return The length of the ray.
         */
        double length() const;

        /**
         * @brief Gets this ray as a unit ray.
         * 
         * @return The resulting unit ray.
         */
        Ray_<Vector> unit() const;

        /**
         * @brief Gets the end point of this ray.
         * 
         * @return The end point of the ray.
         */
        Vector end() const;
    };
}

#include "Core/Math/Ray.tpp"
