/*
    DimValue.cpp

    Implementation of a dimensioning type, storing one-dimensional scale and pixel offsets
*/

#include "Types/DimValue.hpp"

std::ostream& operator<<(std::ostream& o, const DimValue& dval) {
    o << "[" << dval.scale << ", " << dval.offset << "]";
    return o;
}
