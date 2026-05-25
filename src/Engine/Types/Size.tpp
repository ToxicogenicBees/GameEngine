/*
    Size.hpp

    Template implementation for the Size class
*/

#pragma once

#include "Types/Size.hpp"

template<typename Scalar>
Size operator*(const Scalar& s, const Size& size) {
    return {
        size.width_ * (double)s,
        size.height_ * (double)s,
    };
}

template<typename Scalar>
Size Size::operator*(const Scalar& s) const {
    return {
        width_ * (double)s,
        height_ * (double)s,
    };
}

template<typename Scalar>
void Size::operator*=(const Scalar& s) {
    width_ *= (double)s;
    height_ *= (double)s;
}

template<typename Scalar>
Size operator/(const Scalar& s, const Size& size) {
    return {
        size.width_ / (double)s,
        size.height_ / (double)s,
    };
}

template<typename Scalar>
Size Size::operator/(const Scalar& s) const {
    return {
        width_ / (double)s,
        height_ / (double)s,
    };
}

template<typename Scalar>
void Size::operator/=(const Scalar& s) {
    width_ /= (double)s;
    height_ /= (double)s;
}
