/*
    Vector3.hpp

    Declaration for a Vector3 class
*/

#pragma once

#include <cmath>
#include <type_traits>
#include <ostream>

namespace toxico {
    template<typename T>
    struct Vector3_;

    using Vector3 = Vector3_<double>;
    using Vector3i = Vector3_<int>;
    using Vector3f = Vector3_<float>;
    using Vector3d = Vector3_<double>;

    template<typename A, typename B>
    using promote_t = std::common_type_t<A, B>;

    template<typename T>
    struct Vector3_ {
        T x{};
        T y{};
        T z{};

        /**
         * @brief Constructor
         */
        constexpr Vector3_() = default;

        /**
         * @brief Constructor
         * 
         * @param x The x-coordinate of the vector
         * @param y The y-coordinate of the vector
         * @param z The z-coordinate of the vector
         */
        constexpr Vector3_(T x, T y, T z);
        
        /**
         * @brief Copy constructor
         * 
         * @param v The vector being copied
         */
        template<typename U>
        constexpr Vector3_(Vector3_<U> v);
        
        /**
         * @brief Gets a vector where all entries are zero-initialized
         * 
         * @return A vector where all entries are zero-initialized
         */
        static constexpr Vector3_<T> zero();

        /**
         * @brief Gets a vector where all entries are one-initialized
         * 
         * @return A vector where all entries are one-initialized
         */
        static constexpr Vector3_<T> one();

        /**
         * @brief Gets a vector where the x-axis is one-initialized, with the other axis being zero-initialized
         * 
         * @return A vector where the x-axis is one-initialized, with the other axis being zero-initialized
         */
        static constexpr Vector3_<T> xAxis();

        /**
         * @brief Gets a vector where the y-axis is one-initialized, with the other axis being zero-initialized
         * 
         * @return A vector where the y-axis is one-initialized, with the other axis being zero-initialized
         */
        static constexpr Vector3_<T> yAxis();

        /**
         * @brief Gets a vector where the z-axis is one-initialized, with the other axis being zero-initialized
         * 
         * @return A vector where the z-axis is one-initialized, with the other axis being zero-initialized
         */
        static constexpr Vector3_<T> zAxis();

        /**
         * @brief Add this vector to another vector
         * 
         * @param v The other vector being added by
         * @return The resulting vector
         */
        template<typename U>
        constexpr auto operator+(Vector3_<U> v) const;

        /**
         * @brief Subtract this vector to another vector
         * 
         * @param v The other vector being subtracted by
         * @return The resulting vector
         */
        template<typename U>
        constexpr auto operator-(Vector3_<U> v) const;

        /**
         * @brief Unary negate the components of this vector
         * 
         * @return The resulting vector
         */
        constexpr Vector3_<T> operator-() const;

        /**
         * @brief Multiply this vector to a scalar
         * 
         * @param s The scalar being multiplied by
         * @return The resulting vector
         */
        template<typename S>
        requires std::is_arithmetic_v<S>
        constexpr auto operator*(S s) const;

        /**
         * @brief Divide this vector to a scalar
         * 
         * @param v The scalar being divided by
         * @return The resulting vector
         */
        template<typename S>
        requires std::is_arithmetic_v<S>
        constexpr auto operator/(S s) const;

        /**
         * @brief Add another vector into this vector
         * 
         * @param v The vector being added by
         * @return A reference to this vector
         */
        constexpr Vector3_<T>& operator+=(Vector3_<T> v);

        /**
         * @brief Subtract another vector into this vector
         * 
         * @param v The vector being subtracted by
         * @return A reference to this vector
         */
        constexpr Vector3_<T>& operator-=(Vector3_<T> v);

        /**
         * @brief Multiply a scalar into this vector
         * 
         * @param s The scalar being multiplied by
         * @return A reference to this vector
         */
        constexpr Vector3_<T>& operator*=(T s);

        /**
         * @brief Divide a scalar into this vector
         * 
         * @param s The scalar being divided by
         * @return A reference to this vector
         */
        constexpr Vector3_<T>& operator/=(T s);

        /**
         * @brief Compare two Vector3s
         * 
         * @param v The other Vector3 being compared
         * @return If these vectors are equal
         */
        constexpr bool operator==(Vector3_<T> v) const;

        /**
         * @brief Gets the dot product of this vector and another vector
         * 
         * @param v The other vector in the product
         * @return The resulting dot product
         */
        template<typename U>
        constexpr double dot(Vector3_<U> v) const;

        /**
         * @brief Gets the cross product of this vector and another vector
         * 
         * @param v The other vector in the product
         * @return The resulting cross product
         */
        template<typename U>
        constexpr Vector3d cross(Vector3_<U> v) const;

        /**
         * @brief Gets the magnitude of this vector
         * 
         * @return The resulting magnitude
         */
        constexpr double magnitude() const;

        /**
         * @brief Gets the normal of this vector
         * 
         * @return The resulting normal vector
         */
        constexpr Vector3d normal() const;
    };

    /***
     * @brief Overloaded insertion operator
     * 
     * @param o A reference to an output stream
     * @param vector The Vector3 being output to the stream
     * 
     * @result A reference to the output stream being output to
     */
    template<typename T>
    std::ostream& operator<<(std::ostream& o, Vector3_<T> vector);

    /**
     * @brief Multiply a vector by a scalar
     * 
     * @param v The vector being multiplied
     * @param s The scalar being multiplied
     * @return The resulting vector
     */
    template<typename T, typename S>
    constexpr auto operator*(S s, Vector3_<T> v);
}

#include "core/math/Vector3.tpp"
