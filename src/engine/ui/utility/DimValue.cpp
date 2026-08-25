/*
    DimValue.cpp

    Implementation of a dimensioning type, storing one-dimensional scale and pixel offsets
*/

#include "ui/utility/DimValue.hpp"

namespace toxico {
    std::ostream& operator<<(std::ostream& o, const DimValue& dval) {
        o << "[" << dval.scale << ", " << dval.offset << "]";
        return o;
    }
}
