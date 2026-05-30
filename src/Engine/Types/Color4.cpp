/*
    Color4.hpp

    Implementation of a simple RGBA color structure
*/

#include "Types/Color4.hpp"

Color4::Color4(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    : r(r), g(g), b(b), a(a) {}

std::ostream& operator<<(std::ostream& o, const Color4& color) {
    o << "(" << (int)color.r << ", " << (int)color.g << ", " << (int)color.b << ", " << (int)color.a << ")";
    return o;
}
