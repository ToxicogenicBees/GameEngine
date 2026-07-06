/*
    Size.tpp

    Template implementation for the Size class
*/

#pragma once

#include "Geometry/Size.hpp"

template<typename Scalar>
Size operator*(const Scalar& s, Size size) {
    return {
        static_cast<size_t>(size.width_ * s),
        static_cast<size_t>(size.height_ * s),
    };
}

template<typename Scalar>
Size Size::operator*(const Scalar& s) const {
    return {
        static_cast<size_t>(width_ * s),
        static_cast<size_t>(height_ * s),
    };
}

template<typename Scalar>
void Size::operator*=(const Scalar& s) {
    width_ *= s;
    height_ *= s;
}

template<typename Scalar>
Size operator/(const Scalar& s, Size size) {
    return {
        static_cast<size_t>(size.width_ / s),
        static_cast<size_t>(size.height_ / s),
    };
}

template<typename Scalar>
Size Size::operator/(const Scalar& s) const {
    return {
        static_cast<size_t>(width_ / s),
        static_cast<size_t>(height_ / s),
    };
}

template<typename Scalar>
void Size::operator/=(const Scalar& s) {
    width_ /= s;
    height_ /= s;
}
