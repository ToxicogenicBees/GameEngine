/*
    Color4.hpp

    Implementation of a simple RGBA color structure
*/

#include "Graphics/Color4.hpp"

Color4::Color4(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    : r(r), g(g), b(b), a(a) {}

Color4::Color4()
    : r(0), g(0), b(0), a(0) {}

std::ostream& operator<<(std::ostream& o, const Color4& color) {
    o << "(" << static_cast<int>(color.r) << ", " << static_cast<int>(color.g) << ", " << static_cast<int>(color.b) << ", " << static_cast<int>(color.a) << ")";
    return o;
}
