/*
    Vector2_.hpp

    Declaration and implementation for vector classes
*/

#pragma once

#include <iostream>
#include <stdint.h>
#include <cmath>

template <class T>
struct Vector2_ {
    T x;
    T y;

    /***
     * @brief Creates a vector with all components equal to 0
     * 
     * @return A vector with all components equal to 0
     */
    static Vector2_<T> zero() { return Vector2_(T(0), T(0)); }

    /***
     * @brief Creates a vector with all components equal to 1
     * 
     * @return A vector with all components equal to 1
     */
    static Vector2_<T> one() { return Vector2_(T(1), T(1)); }

    /***
     * @brief Creates a vector with the x-component equal to 1
     * 
     * @return A vector with the x-component equal to 1
     */
    static Vector2_<T> xAxis() { return Vector2_(T(1), T(0)); }

    /***
     * @brief Creates a vector with the y-component equal to 1
     * 
     * @return A vector with the y-component equal to 1
     */
    static Vector2_<T> yAxis() { return Vector2_(T(0), T(1)); }

    /***
     * @brief Creates a vector with the desired x- and y-components
     * 
     * @param x     The desired x-component
     * @param y     The desired y-component
     */
    Vector2_(T x, T y);

    /***
     * @brief Creates an uninitialized vector
     */
    Vector2_() = default;

    /***
     * @brief Creates a vector copying the values of another vector
     * 
     * @param vector The vector being copied
     */
    Vector2_(const Vector2_& vector);

    /***
     * @brief Overloaded assignment operator
     * 
     * @param vector Another vector object
     * 
     * @return A reference to this vector
     */
    Vector2_& operator=(const Vector2_& vector);
    
    /***
     * @brief Overloaded addition operator
     * 
     * @param vector Another vector object
     * 
     * @return The resulting vector
     */
    Vector2_ operator+(const Vector2_& vector) const;

    /***
     * @brief Overloaded chained addition + assignment operator
     * 
     * @param vector Another vector object
     */
    void operator+=(const Vector2_& vector);
    
    /***
     * @brief Overloaded subtraction operator
     * 
     * @param vector Another vector object
     * 
     * @return The resulting vector
     */
    Vector2_ operator-(const Vector2_& vector) const;

    /***
     * @brief Overloaded chained subtraction + assignment operator
     * 
     * @param vector Another vector object
     */
    void operator-=(const Vector2_& vector);

    /***
     * @brief Overloaded unary negation operator
     * 
     * @param vector Another vector object
     * 
     * @return The resulting vector
     */
    Vector2_ operator-() const;

    /***
     * @brief Overloaded multiplication operator [Hadamard (component-wise) product]
     * 
     * @param vector Another vector object
     * 
     * @return The Hadamard (component-wise) product of the vectors
     */
    Vector2_ operator*(const Vector2_& vector) const;
    
    /***
     * @brief Overloaded multiplication operator
     * 
     * @param s     A scalar value
     * 
     * @return The resulting vector
     */
    Vector2_ operator*(T s) const;

    /***
     * @brief Overloaded chained multiplication + assignment operator [Hadamard (component-wise) product]
     * 
     * @param vector Another vector object
     */
    void operator*=(const Vector2_& vector);

    /***
     * @brief Overloaded chained multiplication + assignment operator
     * 
     * @param s     A scalar value
     */
    void operator*=(T s);

    /***
     * @brief Overloaded division operator [Hadamard (component-wise) quotient]
     * 
     * @param vector Another vector object
     * 
     * @return The Hadamard (component-wise) quotient of the vectors
     */
    Vector2_ operator/(const Vector2_& vector) const;
    
    /***
     * @brief Overloaded division operator
     * 
     * @param s     A scalar value
     * 
     * @return The resulting vector
     */
    Vector2_ operator/(T s) const;

    /***
     * @brief Overloaded chained division + assignment operator [Hadamard (component-wise) quotient]
     * 
     * @param vector Another vector object
     */
    void operator/=(const Vector2_& vector);

    /***
     * @brief Overloaded chained division + assignment operator
     * 
     * @param s     A scalar value
     */
    void operator/=(T s);

    /***
     * @brief Calculate the dot product between this vector and another vector
     * 
     * @param vector Another vector object
     * 
     * @return The dot product
     */
    T dot(const Vector2_& vector) const;

    /***
     * @brief Calculate the normal of this vector
     * 
     * @return The normal of this vector
     * @retval Vector2_::zero if the magnitude of this vector is extremely close to 0
     */
    Vector2_ normal() const;

    /***
     * @brief Calculate the squared magnitude of this vector
     * 
     * @return The squared magnitude of this vector
     */
    T squaredMagnitude() const;

    /***
     * @brief Calculate the magnitude of this vector
     * 
     * @return The magnitude of this vector
     */
    T magnitude() const;

    /***
     * @brief Calculate the scalar projection of this vector onto another
     * 
     * @param v The vector being projected onto
     * 
     * @return  The scalar projection
     */
    T scalarProjection(const Vector2_<T> v) const;

    /***
     * @brief Calculate the projection of this vector onto another
     * 
     * @param v The vector being projected onto
     * 
     * @return  The projected vector
     */
    Vector2_ projection(const Vector2_<T> v) const;

    /**
     * @brief Calculate the angle between this vector and another
     * 
     * @param v The other vector the angle is between
     * 
     * @return  The angle between the vectors
     */
    T angle(const Vector2_<T> v) const;

    /***
     * @brief Overloaded insertion operator
     * 
     * @param o      A reference to an output stream
     * @param vector The vector being output to the stream
     * 
     * @result A reference to the output stream being output to
     */
    friend std::ostream& operator<<(std::ostream& o, const Vector2_<T>& vector) {
        o << "(" << vector.x << ", " << vector.y << ")";
        return o;
    }
};

using Vector2 = Vector2_<double>;
using Vector2f = Vector2_<float>;
using Vector2d = Vector2_<double>;
using Vector2i = Vector2_<int>;

template <class T>
Vector2_<T>::Vector2_(T x, T y) {
    this->x = x;
    this->y = y;
}

template <class T>
Vector2_<T>::Vector2_(const Vector2_<T>& vector) {
    x = vector.x;
    y = vector.y;
}

template <class T>
Vector2_<T>& Vector2_<T>::operator=(const Vector2_<T>& vector) {
    x = vector.x;
    y = vector.y;

    return *this;
}

template <class T>
Vector2_<T> Vector2_<T>::operator+(const Vector2_<T>& vector) const {
    return Vector2_<T>(x + vector.x, y + vector.y);
}

template <class T>
void Vector2_<T>::operator+=(const Vector2_<T>& vector) {
    x += vector.x;
    y += vector.y;
}

template <class T>
Vector2_<T> Vector2_<T>::operator-(const Vector2_<T>& vector) const {
    return Vector2_(x - vector.x, y - vector.y);
}

template <class T>
void Vector2_<T>::operator-=(const Vector2_<T>& vector) {
    x -= vector.x;
    y -= vector.y;
}

template <class T>
Vector2_<T> Vector2_<T>::operator-() const {
    return Vector2_(-x, -y);
}

template <class T>
Vector2_<T> Vector2_<T>::operator*(const Vector2_& vector) const {
    return Vector2_(x * vector.x, y * vector.y);
}

template <class T>
Vector2_<T> operator*(T s, const Vector2_<T>& vector) {
    return vector * s;
}

template <class T>
Vector2_<T> Vector2_<T>::operator*(T s) const {
    return Vector2_(x * s, y * s);
}

template <class T>
void Vector2_<T>::operator*=(const Vector2_& vector) {
    x *= vector.x;
    y *= vector.y;
}

template <class T>
void Vector2_<T>::operator*=(T s) {
    x *= s;
    y *= s;
}

template <class T>
Vector2_<T> Vector2_<T>::operator/(const Vector2_& vector) const {
    return Vector2_(x / vector.x, y / vector.y);
}

template <class T>
Vector2_<T> operator/(T s, const Vector2_<T>& vector) {
    return vector / s;
}

template <class T>
Vector2_<T> Vector2_<T>::operator/(T s) const {
    return Vector2_(x / s, y / s);
}

template <class T>
void Vector2_<T>::operator/=(const Vector2_& vector) {
    x /= vector.x;
    y /= vector.y;
}

template <class T>
void Vector2_<T>::operator/=(T s) {
    x /= s;
    y /= s;
}

template <class T>
T Vector2_<T>::dot(const Vector2_<T>& vector) const {
    return (x * vector.x) + (y * vector.y);
}

template <class T>
Vector2_<T> Vector2_<T>::normal() const {
    double mag = magnitude();
    return (mag > 1e-8 ? (*this / mag) : Vector2_::zero());
}

template <class T>
T Vector2_<T>::squaredMagnitude() const {
    return dot(*this);
}

template <class T>
T Vector2_<T>::magnitude() const {
    return std::sqrt(squaredMagnitude());
}

template <class T>
T Vector2_<T>::scalarProjection(const Vector2_<T> v) const {
    return dot(v.normal());
}

template <class T>
Vector2_<T> Vector2_<T>::projection(const Vector2_<T> v) const {
    return scalarProjection(v) * v.normal();
}

template <class T>
T Vector2_<T>::angle(const Vector2_<T> v) const {
    return std::acos(dot(v) / magnitude() / v.magnitude());
}
