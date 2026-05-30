/*
    Vector2.tpp

    Template implementation for a GML-style Vector2 class
*/

#pragma once

#include <cmath>

template<typename T>
constexpr Vector2_<T>::Vector2_(T x, T y)
    : x(x), y(y) {}

template<typename T>
template<typename U>
constexpr Vector2_<T>::Vector2_(const Vector2_<U>& v)
    : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)) {}

template<typename T>
constexpr Vector2_<T> Vector2_<T>::zero() {
    return {0, 0};
}

template<typename T>
constexpr Vector2_<T> Vector2_<T>::one() {
    return {1, 1};
}

template<typename T>
constexpr Vector2_<T> Vector2_<T>::xAxis() {
    return {1, 0};
}

template<typename T>
constexpr Vector2_<T> Vector2_<T>::yAxis() {
    return {0, 1};
}

template<typename T>
template<typename U>
constexpr auto Vector2_<T>::operator+(const Vector2_<U>& v) const {
    using R = promote_t<T, U>;
    return Vector2_<R>{
        static_cast<R>(x) + v.x,
        static_cast<R>(y) + v.y
    };
}

template<typename T>
template<typename U>
constexpr auto Vector2_<T>::operator-(const Vector2_<U>& v) const {
    using R = promote_t<T, U>;
    return Vector2_<R>{
        static_cast<R>(x) - v.x,
        static_cast<R>(y) - v.y
    };
}

template<typename T>
constexpr Vector2_<T> Vector2_<T>::operator-() const {
    return {-x, -y};
}

template<typename T>
template<typename S>
requires std::is_arithmetic_v<S>
constexpr auto Vector2_<T>::operator*(S s) const {
    using R = promote_t<T, S>;
    return Vector2_<R>{
        static_cast<R>(x) * s,
        static_cast<R>(y) * s
    };
}

template<typename T>
template<typename S>
requires std::is_arithmetic_v<S>
constexpr auto Vector2_<T>::operator/(S s) const {
    using R = promote_t<T, S>;
    return Vector2_<R>{
        static_cast<R>(x) / s,
        static_cast<R>(y) / s
    };
}

template<typename T>
constexpr Vector2_<T>& Vector2_<T>::operator+=(const Vector2_<T>& v) {
    x += v.x;
    y += v.y;
    return *this;
}

template<typename T>
constexpr Vector2_<T>& Vector2_<T>::operator-=(const Vector2_<T>& v) {
    x -= v.x;
    y -= v.y;
    return *this;
}

template<typename T>
constexpr Vector2_<T>& Vector2_<T>::operator*=(T s) {
    x *= s;
    y *= s;
    return *this;
}

template<typename T>
constexpr Vector2_<T>& Vector2_<T>::operator/=(T s) {
    x /= s;
    y /= s;
    return *this;
}

template<typename T>
constexpr bool Vector2_<T>::operator==(const Vector2_<T>& v) const {
    return (x == v.x && y == v.y);
}

template<typename T>
template<typename U>
constexpr auto Vector2_<T>::dot(const Vector2_<U>& v) const {
    using R = promote_t<T, U>;

    return static_cast<R>(x) * static_cast<R>(v.x) +
           static_cast<R>(y) * static_cast<R>(v.y);
}

template<typename T>
constexpr auto Vector2_<T>::magnitude() const {
    using R = std::common_type_t<T, double>;

    R xx = static_cast<R>(x);
    R yy = static_cast<R>(y);

    return std::sqrt(xx * xx + yy * yy);
}

template<typename T>
constexpr auto Vector2_<T>::normal() const {
    using R = std::common_type_t<T, double>;

    R mag = magnitude();
    if (mag == R(0))
        return Vector2_<R>{0, 0};

    R inv = R(1) / mag;
    return Vector2_<R>{
        static_cast<R>(x) * inv,
        static_cast<R>(y) * inv
    };
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector2_<T>& v) {
    return os << "(" << v.x << ", " << v.y << ")";
}

template<typename T, typename S>
constexpr auto operator*(S s, const Vector2_<T>& v) {
    return v * s;
}
