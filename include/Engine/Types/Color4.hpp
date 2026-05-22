/*
    Color4.hpp

    A simple RGBA color structure
*/

#pragma once

#include <stdint.h>

struct Color4 {
    uint8_t r, g, b, a;

    Color4(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 255)
        : r(r), g(g), b(b), a(a) {}
    
    /***
     * @brief Overloaded insertion operator
     * 
     * @param o A reference to an output stream
     * @param color The color being output to the stream
     * 
     * @result A reference to the output stream being output to
     */
    friend std::ostream& operator<<(std::ostream& o, const Color4& color) {
        o << "(" << (int)color.r << ", " << (int)color.g << ", " << (int)color.b << ", " << (int)color.a << ")";
        return o;
    }
};
