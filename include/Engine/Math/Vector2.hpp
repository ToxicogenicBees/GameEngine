/*
    Vector2.hpp

    Declaration for a GML-style Vector2 class
*/

#pragma once

#include <cmath>
#include <type_traits>
#include <ostream>
#include <functional>

template<typename T>
struct Vector2_;

using Vector2 = Vector2_<double>;
using Vector2i = Vector2_<int>;
using Vector2f = Vector2_<float>;
using Vector2d = Vector2_<double>;

template<typename A, typename B>
using promote_t = std::common_type_t<A, B>;

template<typename T>
struct Vector2_ {
    T x{}, y{};

    /**
     * @brief Constructor
     */
    constexpr Vector2_() = default;

    /**
     * @brief Constructor
     * 
     * @param x The x-coordinate of the vector
     * @param y The y-coordinate of the vector
     */
    constexpr Vector2_(T x, T y);
    
    /**
     * @brief Copy constructor
     * 
     * @param v The vector being copied
     */
    template<typename U>
    constexpr Vector2_(const Vector2_<U>& v);
    
    /**
     * @brief Gets a vector where all entries are zero-initialized
     * 
     * @return A vector where all entries are zero-initialized
     */
    static constexpr Vector2_<T> zero();

    /**
     * @brief Gets a vector where all entries are one-initialized
     * 
     * @return A vector where all entries are one-initialized
     */
    static constexpr Vector2_<T> one();

    /**
     * @brief Gets a vector where the x-axis is one-initialized, with the other axis being zero-initialized
     * 
     * @return A vector where the x-axis is one-initialized, with the other axis being zero-initialized
     */
    static constexpr Vector2_<T> xAxis();

    /**
     * @brief Gets a vector where the y-axis is one-initialized, with the other axis being zero-initialized
     * 
     * @return A vector where the y-axis is one-initialized, with the other axis being zero-initialized
     */
    static constexpr Vector2_<T> yAxis();

    /**
     * @brief Add this vector to another vector
     * 
     * @param v The other vector being added by
     * @return The resulting vector
     */
    template<typename U>
    constexpr auto operator+(const Vector2_<U>& v) const;

    /**
     * @brief Subtract this vector to another vector
     * 
     * @param v The other vector being subtracted by
     * @return The resulting vector
     */
    template<typename U>
    constexpr auto operator-(const Vector2_<U>& v) const;

    /**
     * @brief Unary negate the components of this vector
     * 
     * @return The resulting vector
     */
    constexpr Vector2_<T> operator-() const;

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
    constexpr Vector2_<T>& operator+=(const Vector2_<T>& v);

    /**
     * @brief Subtract another vector into this vector
     * 
     * @param v The vector being subtracted by
     * @return A reference to this vector
     */
    constexpr Vector2_<T>& operator-=(const Vector2_<T>& v);

    /**
     * @brief Multiply a scalar into this vector
     * 
     * @param s The scalar being multiplied by
     * @return A reference to this vector
     */
    constexpr Vector2_<T>& operator*=(T s);

    /**
     * @brief Divide a scalar into this vector
     * 
     * @param s The scalar being divided by
     * @return A reference to this vector
     */
    constexpr Vector2_<T>& operator/=(T s);

    /**
     * @brief Compare two Vector2s
     * 
     * @param v The other Vector2 being compared
     * @return If these vectors are equal
     */
    constexpr bool operator==(const Vector2_<T>& v) const;

    /**
     * @brief Gets the dot product of this vector and another vector
     * 
     * @param v The other vector in the product
     * @return The resulting dot product
     */
    template<typename U>
    constexpr auto dot(const Vector2_<U>& v) const;

    /**
     * @brief Gets the magnitude of this vector
     * 
     * @return The resulting magnitude
     */
    constexpr auto magnitude() const;

    /**
     * @brief Gets the normal of this vector
     * 
     * @return The resulting normal vector
     */
    constexpr auto normal() const;

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Vector2_<U>& v);
};

/**
 * @brief Multiply a vector by a scalar
 * 
 * @param v The vector being multiplied
 * @param s The scalar being multiplied
 * @return The resulting vector
 */
template<typename T, typename S>
constexpr auto operator*(S s, const Vector2_<T>& v);

#include "Math/Vector2.tpp"
