/*
    Mat4x4.cpp

    Implementation of a 4x4 matrix.
*/

#include "core/math/Mat4x4.hpp"
#include "core/geometry/Size.hpp"
#include <stdexcept>
#include <cmath>

namespace toxico {
    Mat4x4::Mat4x4() noexcept
        : data_(Size{3, 3}, 0.0, GridOrder::ColumnMajor) {}

    Mat4x4 Mat4x4::identity() noexcept {
        Mat4x4 result;

        result(0, 0) = 1;
        result(1, 1) = 1;
        result(2, 2) = 1;
        result(3, 3) = 1;

        return result;
    }

    Mat4x4 Mat4x4::translation(const Vector3d& translation) noexcept {
        Mat4x4 result = Mat4x4::identity();

        result(0, 3) = translation.x;
        result(1, 3) = translation.y;
        result(2, 3) = translation.z;

        return result;
    }

    Mat4x4 Mat4x4::rotation(double rotation) noexcept {
        Mat4x4 result;
        auto sin = std::sin(rotation);
        auto cos = std::cos(rotation);

        result(0, 0) = cos;
        result(0, 1) = -sin;
        result(1, 0) = sin;
        result(1, 1) = cos;
        result(2, 2) = 1;

        return result;
    }

    Mat4x4 Mat4x4::scale(const Vector3d& scale) noexcept {
        Mat4x4 result;

        result(0, 0) = scale.x;
        result(1, 1) = scale.y;
        result(2, 2) = scale.y;
        result(3, 3) = 1;

        return result;
    }

    const double& Mat4x4::operator()(size_t row, size_t col) const {
        return data_(row, col);
    }

    double& Mat4x4::operator()(size_t row, size_t col) {
        return data_(row, col);
    }

    const double& Mat4x4::at(size_t row, size_t col) const {
        try {
            return data_.at(row, col);
        }
        catch(...) {
            throw std::out_of_range("Accessed matrix out of range");
        }
    }

    double& Mat4x4::at(size_t row, size_t col) {
        try {
            return data_.at(row, col);
        }
        catch(...) {
            throw std::out_of_range("Accessed matrix out of range");
        }
    }

    Mat4x4 Mat4x4::operator*(const Mat4x4& other) const {
        Mat4x4 result;

        for (size_t i = 0; i < Mat4x4::size; ++i) {
            for (size_t j = 0; j < Mat4x4::size; ++j) {
                double dot = 0;
                for (size_t k = 0; k < Mat4x4::size; ++k)
                    dot += (*this)(i, k) * other(k, j);
                result(i, j) = dot;
            }
        }

        return result;
    }

    Mat4x4& Mat4x4::operator*=(const Mat4x4& other) {
        *this = *this * other;
        return *this;
    }
}
