/*
    DimValue.hpp

    Declaration of a dimensioning type, storing one-dimensional scale and pixel offsets
*/

#pragma once

#include <ostream>

struct DimValue {
    double scale = 0;
    int offset = 0;
};

/***
 * @brief Overloaded insertion operator
 * 
 * @param o A reference to an output stream
 * @param dval The DimValue being output to the stream
 * 
 * @result A reference to the output stream being output to
 */
std::ostream& operator<<(std::ostream& o, const DimValue& dval);
