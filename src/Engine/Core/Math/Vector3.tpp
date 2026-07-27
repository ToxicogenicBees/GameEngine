/*
    Vector3.tpp

    Template implementation for a Vector3 class
*/

#pragma once

#include "Core/Math/Vector3.hpp"
#include <cmath>

namespace toxico {
    template<typename T>
    constexpr Vector3_<T>::Vector3_(T x, T y, T z)
        : x(x),
        y(y),
        z(z)
    {}

    template<typename T>
    template<typename U>
    constexpr Vector3_<T>::Vector3_(Vector3_<U> v)
        : x(static_cast<T>(v.x)),
        y(static_cast<T>(v.y)),
        z(static_cast<T>(v.z))
    {}

    template<typename T>
    constexpr Vector3_<T> Vector3_<T>::zero() {
        return {T{0}, T{0}, T{0}};
    }

    template<typename T>
    constexpr Vector3_<T> Vector3_<T>::one() {
        return {T{1}, T{1}, T{1}};
    }

    template<typename T>
    constexpr Vector3_<T> Vector3_<T>::xAxis() {
        return {T{1}, T{0}, T{0}};
    }

    template<typename T>
    constexpr Vector3_<T> Vector3_<T>::yAxis() {
        return {T{0}, T{1}, T{0}};
    }

    template<typename T>
    constexpr Vector3_<T> Vector3_<T>::zAxis() {
        return {T{0}, T{0}, T{1}};
    }

    template<typename T>
    template<typename U>
    constexpr auto Vector3_<T>::operator+(Vector3_<U> v) const {
        using R = promote_t<T, U>;
        return Vector3_<R>{
            static_cast<R>(x) + v.x,
            static_cast<R>(y) + v.y,
            static_cast<R>(z) + v.z
        };
    }

    template<typename T>
    template<typename U>
    constexpr auto Vector3_<T>::operator-(Vector3_<U> v) const {
        using R = promote_t<T, U>;
        return Vector3_<R>{
            static_cast<R>(x) - v.x,
            static_cast<R>(y) - v.y,
            static_cast<R>(z) - v.z
        };
    }

    template<typename T>
    constexpr Vector3_<T> Vector3_<T>::operator-() const {
        return {-x, -y, -z};
    }

    template<typename T>
    template<typename S>
    requires std::is_arithmetic_v<S>
    constexpr auto Vector3_<T>::operator*(S s) const {
        using R = promote_t<T, S>;
        return Vector3_<R>{
            static_cast<R>(x) * s,
            static_cast<R>(y) * s,
            static_cast<R>(z) * s
        };
    }

    template<typename T>
    template<typename S>
    requires std::is_arithmetic_v<S>
    constexpr auto Vector3_<T>::operator/(S s) const {
        using R = promote_t<T, S>;
        return Vector3_<R>{
            static_cast<R>(x) / s,
            static_cast<R>(y) / s,
            static_cast<R>(z) / s
        };
    }

    template<typename T>
    constexpr Vector3_<T>& Vector3_<T>::operator+=(Vector3_<T> v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    template<typename T>
    constexpr Vector3_<T>& Vector3_<T>::operator-=(Vector3_<T> v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    template<typename T>
    constexpr Vector3_<T>& Vector3_<T>::operator*=(T s) {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    template<typename T>
    constexpr Vector3_<T>& Vector3_<T>::operator/=(T s) {
        x /= s;
        y /= s;
        z /= s;
        return *this;
    }

    template<typename T>
    constexpr bool Vector3_<T>::operator==(Vector3_<T> v) const {
        return (x == v.x && y == v.y && z == v.z);
    }

    template<typename T>
    template<typename U>
    constexpr double Vector3_<T>::dot(Vector3_<U> v) const {
        return static_cast<double>(x) * static_cast<double>(v.x) +
            static_cast<double>(y) * static_cast<double>(v.y) +
            static_cast<double>(z) * static_cast<double>(v.z);
    }

    template<typename T>
    template<typename U>
    constexpr Vector3d Vector3_<T>::cross(Vector3_<U> v) const {
        return Vector3_<R>{
            static_cast<double>(y) * static_cast<double>(v.z) - static_cast<double>(z) * static_cast<double>(v.y),
            static_cast<double>(z) * static_cast<double>(v.x) - static_cast<double>(x) * static_cast<double>(v.z),
            static_cast<double>(x) * static_cast<double>(v.y) - static_cast<double>(y) * static_cast<double>(v.x)
        };
    }

    template<typename T>
    constexpr double Vector3_<T>::magnitude() const {
        return std::sqrt(dot(*this));
    }

    template<typename T>
    constexpr Vector3d Vector3_<T>::normal() const {
        auto mag = magnitude();
        if (mag < 1e-8)
            return Vector3d::zero();

        auto inv = 1.0 / mag;
        return Vector3d{
            static_cast<double>(x) * inv,
            static_cast<double>(y) * inv,
            static_cast<double>(z) * inv
        };
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& os, Vector3_<T> v) {
        return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    }

    template<typename T, typename S>
    constexpr auto operator*(S s, Vector3_<T> v) {
        return v * s;
    }
}
