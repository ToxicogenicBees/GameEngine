/*
    Ray.hpp

    Declaration of a simple ray class.
*/

#pragma once

#include "core/math/Vector.hpp"

namespace toxico {
    template<std::size_t N>
    struct Ray {
        Vector<double, N> direction{Vector<double, N>::zero()};
        Vector<double, N> origin{Vector<double, N>::zero()};

        /**
         * @brief Constructor.
         * 
         * @param origin The origin of the ray.
         * @param direction The direction of the ray.
         */
        constexpr Ray(const Vector<double, N>& origin, const Vector<double, N>& direction);

        /**
         * @brief Constructor.
         *        Assumes the ray origin is at the world origin.
         * 
         * @param direction The direction of the ray.
         */
        constexpr Ray(const Vector<double, N>& direction);

        /**
         * @brief Constructor.
         */
        constexpr Ray() = default;

        /**
         * @brief Gets the length of the ray.
         * 
         * @return The length of the ray.
         */
        constexpr double length() const;

        /**
         * @brief Gets this ray as a unit ray.
         * 
         * @return The resulting unit ray.
         */
        constexpr Ray<N> unit() const;

        /**
         * @brief Gets the end point of this ray.
         * 
         * @return The end point of the ray.
         */
        constexpr Vector<double, N> end() const;
    };

    using Ray2 = Ray<2>;
    using Ray3 = Ray<3>;
}

#include "core/math/Ray.tpp"
