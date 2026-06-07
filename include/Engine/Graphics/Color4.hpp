/*
    Color4.hpp

    Declaration of simple RGBA color structure
*/

#pragma once

#include <cstdint>
#include <ostream>

struct Color4 {
    uint8_t r, g, b, a;

    /**
     * @brief Constructor.
     * 
     * @param r Red component   (0 - 255)
     * @param g Green component (0 - 255)
     * @param b Blue component  (0 - 255)
     * @param a Alpha component (0 - 255)
     */
    Color4(uint8_t, uint8_t g, uint8_t b, uint8_t a);

    /**
     * @brief Constructor.
     */
    Color4();
};

/***
 * @brief Overloaded insertion operator
 * 
 * @param o A reference to an output stream
 * @param color The color being output to the stream
 * 
 * @result A reference to the output stream being output to
 */
std::ostream& operator<<(std::ostream& o, const Color4& color);
