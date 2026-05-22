/*
    Color4.hpp

    Implementation of a simple RGBA color structure
*/

#include "Types/Color4.hpp"

/**
 * @brief Constructor
 * 
 * @param r Red component   (0 - 255)
 * @param g Green component (0 - 255)
 * @param b Blue component  (0 - 255)
 * @param a Alpha component (0 - 255)
 */
Color4::Color4(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    : r(r), g(g), b(b), a(a) {}

/***
 * @brief Overloaded insertion operator
 * 
 * @param o A reference to an output stream
 * @param color The color being output to the stream
 * 
 * @result A reference to the output stream being output to
 */
std::ostream& operator<<(std::ostream& o, const Color4& color) {
    o << "(" << (int)color.r << ", " << (int)color.g << ", " << (int)color.b << ", " << (int)color.a << ")";
    return o;
}
