/*
    DimVector.hpp

    Declaration of a dimensioning type, storing two-dimensional scale and pixel offsets.
*/

#pragma once

#include "Types/DimValue.hpp"
#include <ostream>

struct DimVector {
    DimValue x;
    DimValue y;
};

/***
 * @brief Overloaded insertion operator
 * 
 * @param o A reference to an output stream
 * @param dvec The DimVector being output to the stream
 * 
 * @result A reference to the output stream being output to
 */
std::ostream& operator<<(std::ostream& o, const DimVector& dvec);
