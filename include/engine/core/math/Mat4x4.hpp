/*
    Mat4x4.hpp

    Declaration of a 4x4 matrix.
*/

#pragma once

#include "foundation/containers/Grid.hpp"
#include "core/math/Vector.hpp"

namespace toxico {
    class Mat4x4 {
    private:
        Grid<double> data_;

    public:
        static const size_t size = 3;
        
        /**
         * @brief Constructor.
         */
        Mat4x4() noexcept;

        /**
         * @brief Creates an identity matrix.
         * 
         * @return An identity matrix.
         */
        static Mat4x4 identity() noexcept;

        /**
         * @brief Creates the desired 2D translation matrix.
         * 
         * @param translation The desired translation offset.
         * @return The desired 2D transformation matrix.
         */
        static Mat4x4 translation(const Vector3d& translation) noexcept;

        /**
         * @brief Creates the desired 2D rotation matrix.
         * 
         * @param rotation The desired rotation offset (in radians).
         * @return The desired 2D transformation matrix.
         */
        static Mat4x4 rotation(double rotation) noexcept;

        /**
         * @brief Creates the desired 2D scaling matrix.
         * 
         * @param scale The desired scale offset.
         * @return The desired 2D transformation matrix.
         */
        static Mat4x4 scale(const Vector3d& scale) noexcept;

        /**
         * @brief Access an element in the matrix.
         * 
         * @param row The desired row.
         * @param col The desired column.
         * @return The element in the matrix.
         */
        const double& operator()(size_t row, size_t col) const;

        /**
         * @brief Access an element in the matrix.
         * 
         * @param row The desired row.
         * @param col The desired column.
         * @return The element in the matrix.
         */
        double& operator()(size_t row, size_t col);

        /**
         * @brief Access an element in the matrix.
         *        Throws an out of bounds error if indexed out of bounds.
         * 
         * @param row The desired row.
         * @param col The desired column.
         * @return The element in the matrix.
         */
        const double& at(size_t row, size_t col) const;

        /**
         * @brief Access an element in the matrix.
         *        Throws an out of bounds error if indexed out of bounds.
         * 
         * @param row The desired row.
         * @param col The desired column.
         * @return The element in the matrix.
         */
        double& at(size_t row, size_t col);

        /**
         * @brief Multiply two matrices
         * 
         * @param other The other matrix being multiplied by.
         * @return The resulting matrix.
         */
        Mat4x4 operator*(const Mat4x4& other) const;

        /**
         * @brief Multiply two matrices
         * 
         * @param other The other matrix being multiplied to this one.
         * @return A reference to this modified matrix.
         */
        Mat4x4& operator*=(const Mat4x4& other);

        /**
         * @brief Multiply this matrix by a scalar.
         * 
         * @param s The scalar being multiplied by.
         * @return The resulting matrix.
         */
        template<typename T>
        requires std::is_arithmetic_v<T>
        Mat4x4 operator*(T s) const;

        /**
         * @brief Multiply this matrix by a scalar.
         * 
         * @param s The scalar being multiplied by.
         * @return A reference to this modified matrix.
         */
        template<typename T>
        requires std::is_arithmetic_v<T>
        Mat4x4& operator*=(T s);

        /**
         * @brief Divide this matrix by a scalar.
         * 
         * @param s The scalar being divided by.
         * @return The resulting matrix.
         */
        template<typename T>
        requires std::is_arithmetic_v<T>
        Mat4x4 operator/(T s) const;

        /**
         * @brief Divide this matrix by a scalar.
         * 
         * @param s The scalar being divided by.
         * @return A reference to this modified matrix.
         */
        template<typename T>
        requires std::is_arithmetic_v<T>
        Mat4x4& operator/=(T s);
    };

    /**
     * @brief Multiply a matrix by a scalar.
     * 
     * @param s The scalar being multiplied by.
     * @return The modified matrix.
     */
    template<typename T>
    requires std::is_arithmetic_v<T>
    Mat4x4 operator*(T s, const Mat4x4& mat);
}

#include "core/math/Mat4x4.tpp"
