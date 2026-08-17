/*
    Vector4.tpp

    Template implementation for a Vector4 class
*/

#include "core/math/Vector4.hpp"
#include <cmath>

namespace toxico {
    template<typename T>
    constexpr Vector4_<T>::Vector4_(T x, T y, T z, T w)
        : x(x),
        y(y),
        z(z),
        w(w)
    {}

    template<typename T>
    template<typename U>
    constexpr Vector4_<T>::Vector4_(Vector4_<U> v)
        : x(static_cast<T>(v.x)),
        y(static_cast<T>(v.y)),
        z(static_cast<T>(v.z)),
        w(static_cast<T>(v.w))
    {}

    template<typename T>
    constexpr Vector4_<T> Vector4_<T>::zero() {
        return {T{0}, T{0}, T{0}, T{0}};
    }

    template<typename T>
    constexpr Vector4_<T> Vector4_<T>::one() {
        return {T{1}, T{1}, T{1}, T{1}};
    }

    template<typename T>
    constexpr Vector4_<T> Vector4_<T>::xAxis() {
        return {T{1}, T{0}, T{0}, T{0}};
    }

    template<typename T>
    constexpr Vector4_<T> Vector4_<T>::yAxis() {
        return {T{0}, T{1}, T{0}, T{0}};
    }

    template<typename T>
    constexpr Vector4_<T> Vector4_<T>::zAxis() {
        return {T{0}, T{0}, T{1}, T{0}};
    }

    template<typename T>
    constexpr Vector4_<T> Vector4_<T>::wAxis() {
        return {T{0}, T{0}, T{0}, T{1}};
    }

    template<typename T>
    template<typename U>
    constexpr auto Vector4_<T>::operator+(Vector4_<U> v) const {
        using R = promote_t<T, U>;
        return Vector4_<R>{
            static_cast<R>(x) + v.x,
            static_cast<R>(y) + v.y,
            static_cast<R>(z) + v.z,
            static_cast<R>(w) + v.w
        };
    }

    template<typename T>
    template<typename U>
    constexpr auto Vector4_<T>::operator-(Vector4_<U> v) const {
        using R = promote_t<T, U>;
        return Vector4_<R>{
            static_cast<R>(x) - v.x,
            static_cast<R>(y) - v.y,
            static_cast<R>(z) - v.z,
            static_cast<R>(w) - v.w
        };
    }

    template<typename T>
    constexpr Vector4_<T> Vector4_<T>::operator-() const {
        return {-x, -y, -z, -w};
    }

    template<typename T>
    template<typename S>
    requires std::is_arithmetic_v<S>
    constexpr auto Vector4_<T>::operator*(S s) const {
        using R = promote_t<T, S>;
        return Vector4_<R>{
            static_cast<R>(x) * s,
            static_cast<R>(y) * s,
            static_cast<R>(z) * s,
            static_cast<R>(w) * s
        };
    }

    template<typename T>
    template<typename S>
    requires std::is_arithmetic_v<S>
    constexpr auto Vector4_<T>::operator/(S s) const {
        using R = promote_t<T, S>;
        return Vector4_<R>{
            static_cast<R>(x) / s,
            static_cast<R>(y) / s,
            static_cast<R>(z) / s,
            static_cast<R>(w) / s
        };
    }

    template<typename T>
    constexpr Vector4_<T>& Vector4_<T>::operator+=(Vector4_<T> v) {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
        return *this;
    }

    template<typename T>
    constexpr Vector4_<T>& Vector4_<T>::operator-=(Vector4_<T> v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        w -= v.w;
        return *this;
    }

    template<typename T>
    constexpr Vector4_<T>& Vector4_<T>::operator*=(T s) {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }

    template<typename T>
    constexpr Vector4_<T>& Vector4_<T>::operator/=(T s) {
        x /= s;
        y /= s;
        z /= s;
        w /= s;
        return *this;
    }

    template<typename T>
    constexpr bool Vector4_<T>::operator==(Vector4_<T> v) const {
        return (x == v.x && y == v.y && z == v.z && z == v.w);
    }

    template<typename T>
    template<typename U>
    constexpr double Vector4_<T>::dot(Vector4_<U> v) const {
        return static_cast<double>(x) * static_cast<double>(v.x) +
            static_cast<double>(y) * static_cast<double>(v.y) +
            static_cast<double>(z) * static_cast<double>(v.z) +
            static_cast<double>(w) * static_cast<double>(v.w);
    }

    template<typename T>
    constexpr double Vector4_<T>::magnitude() const {
        return std::sqrt(dot(*this));
    }

    template<typename T>
    constexpr Vector4d Vector4_<T>::normal() const {
        auto mag = magnitude();
        if (mag < 1e-8)
            return Vector4d::zero();

        auto inv = 1.0 / mag;
        return Vector4d{
            static_cast<double>(x) * inv,
            static_cast<double>(y) * inv,
            static_cast<double>(z) * inv,
            static_cast<double>(w) * inv
        };
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& os, Vector4_<T> v) {
        return os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
    }

    template<typename T, typename S>
    constexpr auto operator*(S s, Vector4_<T> v) {
        return v * s;
    }
}
