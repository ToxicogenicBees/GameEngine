/*
    DimValue.hpp

    Declaration of a dimensioning type, storing one-dimensional scale and pixel offsets
*/

#pragma once

#include "foundation/utility/fp_type.hpp"
#include <ostream>

namespace toxico {
    struct DimValue {
        fp_type scale = 0;
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
}
