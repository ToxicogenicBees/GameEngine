/*
    Quaternion.tpp

    Template implementation of a quaternion object.
*/

#include "core/math/Quaternion.hpp"

namespace toxico {
    template <typename T>
    requires std::is_arithmetic_v<T>
    Quaternion Quaternion::operator*(T scalar) const noexcept {
        double s = static_cast<double>(scalar);
        return Quaternion(a_ * s, b_ * s, c_ * s, d_ * s);
    }

    template <typename T>
    requires std::is_arithmetic_v<T>
    Quaternion& Quaternion::operator*=(T scalar) noexcept {
        *this = *this * scalar;
        return *this;
    }

    template <typename T>
    requires std::is_arithmetic_v<T>
    Quaternion Quaternion::operator/(T scalar) const noexcept {
        double s = static_cast<double>(scalar);
        return Quaternion(a_ / s, b_ / s, c_ / s, d_ / s);
    }

    template <typename T>
    requires std::is_arithmetic_v<T>
    Quaternion& Quaternion::operator/=(T scalar) noexcept {
        *this = *this / scalar;
        return *this;
    }

    template <typename T>
    requires std::is_arithmetic_v<T>
    Quaternion operator*(T scalar, Quaternion quaternion) noexcept {
        return quaternion * scalar;
    }
}
