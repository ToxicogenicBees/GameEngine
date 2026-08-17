/*
    Vector4.hpp

    Declaration for a Vector4 class
*/

#pragma once

#include <cmath>
#include <type_traits>
#include <ostream>

namespace toxico {
    template<typename T>
    struct Vector4_;

    using Vector4 = Vector4_<double>;
    using Vector4i = Vector4_<int>;
    using Vector4f = Vector4_<float>;
    using Vector4d = Vector4_<double>;

    template<typename A, typename B>
    using promote_t = std::common_type_t<A, B>;

    template<typename T>
    struct Vector4_ {
        T x{};
        T y{};
        T z{};
        T w{};

        /**
         * @brief Constructor
         */
        constexpr Vector4_() = default;

        /**
         * @brief Constructor
         * 
         * @param x The x-coordinate of the vector
         * @param y The y-coordinate of the vector
         * @param z The z-coordinate of the vector
         * @param z The w-coordinate of the vector
         */
        constexpr Vector4_(T x, T y, T z, T w);
        
        /**
         * @brief Copy constructor
         * 
         * @param v The vector being copied
         */
        template<typename U>
        constexpr Vector4_(Vector4_<U> v);
        
        /**
         * @brief Gets a vector where all entries are zero-initialized
         * 
         * @return A vector where all entries are zero-initialized
         */
        static constexpr Vector4_<T> zero();

        /**
         * @brief Gets a vector where all entries are one-initialized
         * 
         * @return A vector where all entries are one-initialized
         */
        static constexpr Vector4_<T> one();

        /**
         * @brief Gets a vector where the x-axis is one-initialized, with the other axis being zero-initialized
         * 
         * @return A vector where the x-axis is one-initialized, with the other axis being zero-initialized
         */
        static constexpr Vector4_<T> xAxis();

        /**
         * @brief Gets a vector where the y-axis is one-initialized, with the other axis being zero-initialized
         * 
         * @return A vector where the y-axis is one-initialized, with the other axis being zero-initialized
         */
        static constexpr Vector4_<T> yAxis();

        /**
         * @brief Gets a vector where the z-axis is one-initialized, with the other axis being zero-initialized
         * 
         * @return A vector where the z-axis is one-initialized, with the other axis being zero-initialized
         */
        static constexpr Vector4_<T> zAxis();

        /**
         * @brief Gets a vector where the w-axis is one-initialized, with the other axis being zero-initialized
         * 
         * @return A vector where the w-axis is one-initialized, with the other axis being zero-initialized
         */
        static constexpr Vector4_<T> wAxis();

        /**
         * @brief Add this vector to another vector
         * 
         * @param v The other vector being added by
         * @return The resulting vector
         */
        template<typename U>
        constexpr auto operator+(Vector4_<U> v) const;

        /**
         * @brief Subtract this vector to another vector
         * 
         * @param v The other vector being subtracted by
         * @return The resulting vector
         */
        template<typename U>
        constexpr auto operator-(Vector4_<U> v) const;

        /**
         * @brief Unary negate the components of this vector
         * 
         * @return The resulting vector
         */
        constexpr Vector4_<T> operator-() const;

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
        constexpr Vector4_<T>& operator+=(Vector4_<T> v);

        /**
         * @brief Subtract another vector into this vector
         * 
         * @param v The vector being subtracted by
         * @return A reference to this vector
         */
        constexpr Vector4_<T>& operator-=(Vector4_<T> v);

        /**
         * @brief Multiply a scalar into this vector
         * 
         * @param s The scalar being multiplied by
         * @return A reference to this vector
         */
        constexpr Vector4_<T>& operator*=(T s);

        /**
         * @brief Divide a scalar into this vector
         * 
         * @param s The scalar being divided by
         * @return A reference to this vector
         */
        constexpr Vector4_<T>& operator/=(T s);

        /**
         * @brief Compare two Vector4s
         * 
         * @param v The other Vector4 being compared
         * @return If these vectors are equal
         */
        constexpr bool operator==(Vector4_<T> v) const;

        /**
         * @brief Gets the dot product of this vector and another vector
         * 
         * @param v The other vector in the product
         * @return The resulting dot product
         */
        template<typename U>
        constexpr double dot(Vector4_<U> v) const;

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
        constexpr Vector4d normal() const;
    };

    /***
     * @brief Overloaded insertion operator
     * 
     * @param o A reference to an output stream
     * @param vector The Vector4 being output to the stream
     * 
     * @result A reference to the output stream being output to
     */
    template<typename T>
    std::ostream& operator<<(std::ostream& o, Vector4_<T> vector);

    /**
     * @brief Multiply a vector by a scalar
     * 
     * @param v The vector being multiplied
     * @param s The scalar being multiplied
     * @return The resulting vector
     */
    template<typename T, typename S>
    constexpr auto operator*(S s, Vector4_<T> v);
}

#include "core/math/Vector4.tpp"
