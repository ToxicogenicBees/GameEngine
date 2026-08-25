/*
    Quaternion.hpp

    Declaration of a quaternion object.
*/

#pragma once

#include "foundation/math/Vector.hpp"
#include "foundation/math/Mat3x3.hpp"
#include <concepts>

namespace toxico {
    class Quaternion {
    private:
        double a_{0.0};
        double b_{0.0};
        double c_{0.0};
        double d_{0.0};

    public:
        /**
         * @brief Constructor.
         * 
         * @param a The real component of the quaternion.
         * @param b The i component of the quaternion.
         * @param c The j component of the quaternion.
         * @param d The k component of the quaternion.
         */
        Quaternion(double a, double b, double c, double d) noexcept;

        /**
         * @brief Constructor.
         */
        Quaternion() noexcept = default;

        /**
         * @brief Gets the identitiy quaternion.
         * 
         * @return The identity quaternion.
         */
        static Quaternion identity() noexcept;
        
        /**
         * @brief Gets the quaternion defined by an axis angle.
         * 
         * @param axis The axis of the quaternion.
         * @param angle The angle of the quaternion.
         */
        static Quaternion fromAxisAngle(Vector3 axis, double angle) noexcept;
        
        /**
         * @brief Gets the quaternion defined by a 3x3 rotation matrix.
         * 
         * @param mat The 3x3 rotation matrix.
         */
        static Quaternion fromMat3x3(const Mat3x3& mat) noexcept;

        /**
         * @brief Adds two quaternions together.
         * 
         * @param other Another quaternion.
         * @return The sum of the quaternions.
         */
        Quaternion operator+(const Quaternion& other) const noexcept;

        /**
         * @brief Adds another quaternion to this one.
         * 
         * @param other Another quaternion.
         * @return The modified quaternion.
         */
        Quaternion& operator+=(Quaternion other) noexcept;

        /**
         * @brief Subtracts two quaternions together.
         * 
         * @param other Another quaternion.
         * @return The difference of the quaternions.
         */
        Quaternion operator-(const Quaternion& other) const noexcept;

        /**
         * @brief Subtracts another quaternion to this one.
         * 
         * @param other Another quaternion.
         * @return The modified quaternion.
         */
        Quaternion& operator-=(Quaternion other) noexcept;

        /**
         * @brief Multiplies two quaternions together.
         * 
         * @param other Another quaternion.
         * @return The product of the quaternions.
         */
        Quaternion operator*(const Quaternion& other) const noexcept;

        /**
         * @brief Multiplies this quaternion with a scalar.
         * 
         * @param scalar The scalar being multiplied by.
         * @return The resulting quaternion.
         */
        template <typename T>
        requires std::is_arithmetic_v<T>
        Quaternion operator*(T scalar) const noexcept;

        /**
         * @brief Rotates a vector by this quaternion.
         * 
         * @param vector The vector being rotated.
         * @return The rotated vector.
         */
        Vector3 operator*(const Vector3& vector) const noexcept;

        /**
         * @brief Multiplies another quaternion to this one.
         * 
         * @param other Another quaternion.
         * @return The modified quaternion.
         */
        Quaternion& operator*=(Quaternion other) noexcept;

        /**
         * @brief Multiplies this quaternion by a scalar.
         * 
         * @param scalar The scalar being multiplied by.
         * @return The modified quaternion.
         */
        template <typename T>
        requires std::is_arithmetic_v<T>
        Quaternion& operator*=(T scalar) noexcept;

        /**
         * @brief Divides this quaternion with a scalar.
         * 
         * @param scalar The scalar being divided by.
         * @return The resulting quaternion.
         */
        template <typename T>
        requires std::is_arithmetic_v<T>
        Quaternion operator/(T scalar) const noexcept;

         /**
         * @brief Divides this quaternion by a scalar.
         * 
         * @param scalar The scalar being divided by.
         * @return The resulting quaternion.
         */
        template <typename T>
        requires std::is_arithmetic_v<T>
        Quaternion& operator/=(T scalar) noexcept;

        /**
         * @brief Gets the conjugate of this quaternion.
         * 
         * @return The conjugate of this quaternion.
         */
        Quaternion conjugate() const noexcept;

        /**
         * @brief Normalizes this quaternion.
         */
        void normalize() noexcept;

        /**
         * @brief Gets the normalized quaternion for this quaternion.
         * 
         * @return The normalized quaternion.
         */
        Quaternion normalized() const noexcept;

        /**
         * @brief Rotates a vector by this quaternion.
         * 
         * @param vector The vector being rotated.
         * @return The rotated vector.
         */
        Vector3 rotate(const Vector3& vector) const noexcept;

        /**
         * @brief Converts the quaternion to a 3x3 rotation matrix.
         * 
         * @return The resulting 3x3 rotation matrix.
         */
        Mat3x3 toMat3x3() const noexcept;

        /**
         * @brief Converts the quaternion to a 3x3 rotation matrix.
         * 
         * @return The resulting 3x3 rotation matrix.
         */
        operator Mat3x3() const noexcept;

        /**
         * @brief Converts the quaternion to Euler angles.
         * 
         * @return This quaternion as Euler angles
         */
        Vector3 eulerAngles() const noexcept;

        /**
         * @brief Computes the dot product of this quaternion with another.
         * 
         * @param other Another quaternion.
         * @return The dot product.
         */
        double dot(Quaternion other) const noexcept;
    };

    /**
     * @brief Multiplies a quaternion by a scalar.
     * 
     * @param scalar The scalar being multiplied by.
     * @return The modified quaternion.
     */
    template <typename T>
    requires std::is_arithmetic_v<T>
    Quaternion operator*(T scalar, Quaternion quaternion) noexcept;

    /**
     * @brief Lerps two quaternions.
     * 
     * @param a The starting quaternion.
     * @param b The ending quaternion.
     * @param t The lerping factor.
     * @return The lerped quaternion.
     */
    Quaternion lerp(Quaternion a, Quaternion b, double t) noexcept;

    /**
     * @brief Slerps two quaternions.
     * 
     * @param a The starting quaternion.
     * @param b The ending quaternion.
     * @param t The slerping factor.
     * @return The slerped quaternion.
     */
    Quaternion slerp(Quaternion a, Quaternion b, double t) noexcept;
}

#include "foundation/math/Quaternion.tpp"
