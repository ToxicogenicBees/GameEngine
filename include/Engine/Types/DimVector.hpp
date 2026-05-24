/*
    DimVector.hpp

    Declaration of a dimensioning type, storing two-dimensional scale and pixel offsets.
*/

#pragma once

#include "Types/DimValue.hpp"

struct DimVector {
    DimValue x;
    DimValue y;
};
