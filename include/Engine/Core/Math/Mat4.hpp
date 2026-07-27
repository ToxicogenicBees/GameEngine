/*
    Mat4.hpp

    Declaration of a 4x4 matrix.
*/

#pragma once

#include <array>

namespace toxico {
    class Mat4 {
    private:
        std::array<double, 16> data_;
    };
}
