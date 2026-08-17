/*
    Mat3x3.hpp

    Declaration of a 3x3 matrix.
*/

#pragma once

#include "core/math/Vector2.hpp"
#include <array>

namespace toxico {
    class Mat3x3 {
    private:
        std::array<double, 9> data_{0};

    public:
        /**
         * @brief Constructor.
         */

        /**
         * @brief Creates the desired 2D translation matrix.
         * 
         * @param translation The desired translation offset.
         * @return The desired 2D transformation matrix.
         */
        static Mat3x3 translation(const Vector2d& translation) noexcept;

        /**
         * @brief Creates the desired 2D rotation matrix.
         * 
         * @param rotation The desired rotation offset (in radians).
         * @return The desired 2D transformation matrix.
         */
        static Mat3x3 rotation(double rotation) noexcept;

        /**
         * @brief Creates the desired 2D scaling matrix.
         * 
         * @param scale The desired scale offset.
         * @return The desired 2D transformation matrix.
         */
        static Mat3x3 scale(const Vector2d& scale) noexcept;

        /**
         * @brief Access an element in the matrix.
         *        Throws an out of bounds error if indexed out of bounds.
         * 
         * @param row The desired row.
         * @param col The desired column.
         * @return The element in the matrix.
         */
        const double& operator()(size_t row, size_t col) const;

        /**
         * @brief Access an element in the matrix.
         *        Throws an out of bounds error if indexed out of bounds.
         * 
         * @param row The desired row.
         * @param col The desired column.
         * @return The element in the matrix.
         */
        double& operator()(size_t row, size_t col);
    };
}

#include "core/math/Mat3x3.tpp"
