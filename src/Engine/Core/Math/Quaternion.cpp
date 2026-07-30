/*
    Quaternion.cpp

    Implementation of a quaternion object.
*/

#include "Core/Math/Quaternion.hpp"
#include <algorithm>
#include <cmath>

namespace toxico {
    Quaternion::Quaternion(double a, double b, double c, double d) noexcept
        : a_(a), b_(b), c_(c), d_(d) {}

    Quaternion Quaternion::identity() noexcept {
        return Quaternion(1.0, 0.0, 0.0, 0.0);
    }
    
    Quaternion Quaternion::fromAxisAngle(Vector3d axis, double angle) noexcept {
        axis = axis.normal();

        auto sin_a = std::sin(0.5 * angle);

        return Quaternion(
            axis.x * sin_a,
            axis.y * sin_a,
            axis.z * sin_a,
            std::cos(.5 * angle)
        );
    }
    
    Quaternion Quaternion::fromMat3x3(const Mat3x3& mat) noexcept {
        // @TODO: Implement quaternion method
        return {};
    }

    Quaternion Quaternion::operator+(const Quaternion& other) const noexcept {
        return Quaternion(
            a_ + other.a_,
            b_ + other.b_,
            c_ + other.c_,
            d_ + other.d_
        );
    }

    Quaternion& Quaternion::operator+=(Quaternion other) noexcept {
        a_ += other.a_;
        b_ += other.b_;
        c_ += other.c_;
        d_ += other.d_;
        return *this;
    }

    Quaternion Quaternion::operator-(const Quaternion& other) const noexcept {
        return Quaternion(
            a_ - other.a_,
            b_ - other.b_,
            c_ - other.c_,
            d_ - other.d_
        );
    }

    Quaternion& Quaternion::operator-=(Quaternion other) noexcept {
        a_ -= other.a_;
        b_ -= other.b_;
        c_ -= other.c_;
        d_ -= other.d_;
        return *this;
    }

    Quaternion Quaternion::operator*(const Quaternion& other) const noexcept {
        return Quaternion(
            a_ * other.a_ + b_ * other.b_ + c_ * other.c_ + d_ * other.d_,
            a_ * other.b_ + b_ * other.a_ + c_ * other.d_ + d_ * other.c_,
            a_ * other.c_ + b_ * other.d_ + c_ * other.a_ + d_ * other.b_,
            a_ * other.d_ + b_ * other.c_ + c_ * other.b_ + d_ * other.a_
        );
    }

    Vector3d Quaternion::operator*(const Vector3d& vector) const noexcept {
        return rotate(vector);
    }

    Quaternion& Quaternion::operator*=(Quaternion other) noexcept {
        *this = *this * other;
        return *this;
    }

    Quaternion Quaternion::conjugate() const noexcept {
        return Quaternion(a_, -b_, -c_, -d_);
    }

    void Quaternion::normalize() noexcept {
        *this = normalized();
    }

    Quaternion Quaternion::normalized() const noexcept {
        auto mag = std::sqrt(a_ * a_ + b_ * b_ + c_ * c_ + d_ * d_);
        if (mag <= 1e-8)
            return Quaternion(0.0, 0.0, 0.0, 0.0);
        return *this / mag;
    }

    Vector3d Quaternion::rotate(const Vector3d& vector) const noexcept {
        auto v = Quaternion(0, vector.x, vector.y, vector.z);
        auto v_rot = *this * v * conjugate();
        return Vector3d(v_rot.b_, v_rot.c_, v_rot.d_);
    }

    Mat3x3 Quaternion::toMat3x3() const noexcept {
        // @TODO: Implement quaternion method
        return {};
    }

    Quaternion::operator Mat3x3() const noexcept {
        return toMat3x3();
    }

    Vector3d Quaternion::eulerAngles() const noexcept {
        // @TODO: Implement quaternion method
        return {};
    }

    double Quaternion::dot(Quaternion other) const noexcept {
        return a_ * other.a_, b_ * other.b_, c_ * other.c_, d_ * other.d_;
    }

    Quaternion lerp(Quaternion from, Quaternion to, double t) noexcept {
        t = std::clamp(t, 0.0, 1.0);
        return (1.0 - t) * from + t * to;
    }

    Quaternion slerp(Quaternion from, Quaternion to, double t) noexcept {
        t = std::clamp(t, 0.0, 1.0);
        double angle = std::acos(from.dot(to));
        return std::sin((1 - t) * angle) / std::sin(angle) * from + std::sin(t * angle) / std::sin(angle) * to;
    }
}

#include "Core/Math/Quaternion.tpp"
