/*
    DimVector.cpp

    Implementation of a dimensioning type, storing two-dimensional scale and pixel offsets.
*/

#include "types/DimVector.hpp"

namespace toxico {
    std::ostream& operator<<(std::ostream& o, const DimVector& dvec) {
        o << "[" << dvec.x << ", " << dvec.y << "]";
        return o;
    }
}
