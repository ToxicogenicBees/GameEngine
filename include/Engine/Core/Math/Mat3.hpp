/*
    Mat3.hpp

    Declaration of a 3x3 matrix.
*/

#pragma once

#include <array>

namespace toxico {
    class Mat3 {
    private:
        std::array<double, 9> data_;
    };
}
