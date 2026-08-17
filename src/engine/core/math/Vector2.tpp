/*
    Vector2.tpp

    Template implementation for a Vector2 class
*/

#include <cmath>

namespace toxico {
    template<typename T>
    constexpr Vector2_<T>::Vector2_(T x, T y)
        : x(x),
        y(y)
    {}

    template<typename T>
    template<typename U>
    constexpr Vector2_<T>::Vector2_(Vector2_<U> v)
        : x(static_cast<T>(v.x)),
        y(static_cast<T>(v.y))
    {}

    template<typename T>
    constexpr Vector2_<T> Vector2_<T>::zero() {
        return {T{0}, T{0}};
    }

    template<typename T>
    constexpr Vector2_<T> Vector2_<T>::one() {
        return {T{1}, T{1}};
    }

    template<typename T>
    constexpr Vector2_<T> Vector2_<T>::xAxis() {
        return {T{1}, T{0}};
    }

    template<typename T>
    constexpr Vector2_<T> Vector2_<T>::yAxis() {
        return {T{0}, T{1}};
    }

    template<typename T>
    template<typename U>
    constexpr auto Vector2_<T>::operator+(Vector2_<U> v) const {
        using R = promote_t<T, U>;
        return Vector2_<R>{
            static_cast<R>(x) + v.x,
            static_cast<R>(y) + v.y
        };
    }

    template<typename T>
    template<typename U>
    constexpr auto Vector2_<T>::operator-(Vector2_<U> v) const {
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
    constexpr Vector2_<T>& Vector2_<T>::operator+=(Vector2_<T> v) {
        x += v.x;
        y += v.y;
        return *this;
    }

    template<typename T>
    constexpr Vector2_<T>& Vector2_<T>::operator-=(Vector2_<T> v) {
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
    constexpr bool Vector2_<T>::operator==(Vector2_<T> v) const {
        return (x == v.x && y == v.y);
    }

    template<typename T>
    template<typename U>
    constexpr double Vector2_<T>::dot(Vector2_<U> v) const {
        return static_cast<double>(x) * static_cast<double>(v.x) +
            static_cast<double>(y) * static_cast<double>(v.y);
    }

    template<typename T>
    constexpr double Vector2_<T>::magnitude() const {
        return std::sqrt(dot(*this));
    }

    template<typename T>
    constexpr Vector2d Vector2_<T>::normal() const {
        auto mag = magnitude();
        if (mag < 1e-8)
            return Vector2d::zero();

        auto inv = 1.0 / mag;
        return Vector2d{
            static_cast<double>(x) * inv,
            static_cast<double>(y) * inv
        };
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& os, Vector2_<T> v) {
        return os << "(" << v.x << ", " << v.y << ")";
    }

    template<typename T, typename S>
    constexpr auto operator*(S s, Vector2_<T> v) {
        return v * s;
    }
}
