/*
    Mat3x3.cpp

    Implementation of a 3x3 matrix.
*/

#include "core/math/Mat3x3.hpp"
#include "core/geometry/Size.hpp"
#include <stdexcept>
#include <cmath>

namespace toxico {
    Mat3x3::Mat3x3() noexcept
        : data_(Size{3, 3}, 0.0, GridOrder::ColumnMajor) {}

    Mat3x3 Mat3x3::identity() noexcept {
        Mat3x3 result;

        result(0, 0) = 1;
        result(1, 1) = 1;
        result(2, 2) = 1;

        return result;
    }

    Mat3x3 Mat3x3::translation(const Vector2d& translation) noexcept {
        Mat3x3 result = Mat3x3::identity();

        result(0, 2) = translation.x;
        result(1, 2) = translation.y;

        return result;
    }

    Mat3x3 Mat3x3::rotation(double rotation) noexcept {
        Mat3x3 result;
        auto sin = std::sin(rotation);
        auto cos = std::cos(rotation);

        result(0, 0) = cos;
        result(0, 1) = -sin;
        result(1, 0) = sin;
        result(1, 1) = cos;
        result(2, 2) = 1;

        return result;
    }

    Mat3x3 Mat3x3::scale(const Vector2d& scale) noexcept {
        Mat3x3 result;

        result(0, 0) = scale.x;
        result(1, 1) = scale.y;
        result(2, 2) = 1;

        return result;
    }

    const double& Mat3x3::operator()(size_t row, size_t col) const {
        return data_(row, col);
    }

    double& Mat3x3::operator()(size_t row, size_t col) {
        return data_(row, col);
    }

    const double& Mat3x3::at(size_t row, size_t col) const {
        try {
            return data_.at(row, col);
        }
        catch(...) {
            throw std::out_of_range("Accessed matrix out of range");
        }
    }

    double& Mat3x3::at(size_t row, size_t col) {
        try {
            return data_.at(row, col);
        }
        catch(...) {
            throw std::out_of_range("Accessed matrix out of range");
        }
    }

    Mat3x3 Mat3x3::operator*(const Mat3x3& other) const {
        Mat3x3 result;

        for (size_t i = 0; i < 3; ++i) {
            for (size_t j = 0; j < 3; ++j) {
                double dot = 0;
                for (size_t k = 0; k < 3; ++k)
                    dot += (*this)(i, k) * other(k, j);
                result(i, j) = dot;
            }
        }

        return result;
    }

    Mat3x3& Mat3x3::operator*=(const Mat3x3& other) {
        *this = *this * other;
        return *this;
    }
}
