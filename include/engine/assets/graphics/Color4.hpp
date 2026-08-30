/*
    Color4.hpp

    Declaration of simple RGBA color structure
*/

#pragma once

#include <functional>
#include <cstdint>
#include <ostream>
#include <string>

namespace toxico {
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
        Color4(uint8_t, uint8_t g, uint8_t b, uint8_t a) noexcept;

        /**
         * @brief Constructor.
         */
        Color4() noexcept;

        /**
         * @brief Gets a fully transparent color.
         * 
         * @return A fully transparent color.
         */
        static Color4 transparent() noexcept;

        /**
         * @brief Compared two colors.
         * 
         * @param other Another color
         * @return If the colors are the same.
         */
        bool operator==(const Color4& other) const noexcept = default;

        /**
         * @brief Gets the color at the desired channel.
         * 
         * @param channel The desired channel.
         * @return The value of the desired channel.
         * 
         * Throws an invalid argument error if an invalid channel is passed.
         * 0 -> Red
         * 1 -> Green
         * 2 -> Blue
         * 3 -> Alpha
         */
        uint8_t operator[](std::size_t channel) const;
        uint8_t& operator[](std::size_t channel);

        /**
         * @brief Gets the color as a hex string.
         * 
         * @return The color as a hex string.
         */
        std::string toHex() const noexcept;

        /**
         * @brief Gets the color as an RBGA-format string.
         * 
         * @return The color as an RBGA-format string.
         */
        std::string toString() const noexcept;
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
}

namespace std {
    template<>
    struct hash<toxico::Color4> {
        /**
         * @brief Calculates the hash of a hashable object.
         * 
         * @param object A hashable object.
         * @return A deterministic hash for the object.
         */
        inline std::size_t operator()(const toxico::Color4& color) const noexcept {
            return (static_cast<std::size_t>(color.r) << 24) |
                   (static_cast<std::size_t>(color.g) << 16) |
                   (static_cast<std::size_t>(color.b) << 8)  |
                   static_cast<std::size_t>(color.a);
        }
    };
}
