/*
    Color4.hpp

    Implementation of a simple RGBA color structure
*/

#include "assets/graphics/Color4.hpp"
#include <stdexcept>
#include <array>
#include <sstream>
#include <iomanip>

namespace {
    const std::array<uint8_t toxico::Color4::*, 4> COLOR_CHANNELS = {
        &toxico::Color4::r, &toxico::Color4::g, &toxico::Color4::b, &toxico::Color4::a
    };
}

namespace toxico {
    Color4::Color4(uint8_t r, uint8_t g, uint8_t b, uint8_t a) noexcept
        : r(r),
          g(g),
          b(b),
          a(a)
        {}

    Color4::Color4() noexcept
        : r(0),
          g(0),
          b(0),
          a(0)
    {}

    Color4 Color4::transparent() noexcept {
        return Color4(0x00, 0x00, 0x00, 0x00);
    }

    uint8_t Color4::operator[](std::size_t channel) const {
        if (channel >= 4)
            throw std::invalid_argument("Invalid color channel");

        return this->*COLOR_CHANNELS[channel];
    }

    uint8_t& Color4::operator[](std::size_t channel) {
        if (channel >= 4)
            throw std::invalid_argument("Invalid color channel");

        return this->*COLOR_CHANNELS[channel];
    }

    std::string Color4::toHex() const noexcept {
        std::stringstream ss;
        ss << std::hex;

        ss << (r >> 4) << (r & 0x0F)
        << (g >> 4) << (g & 0x0F)
        << (b >> 4) << (b & 0x0F)
        << (a >> 4) << (a & 0x0F);

        return ss.str();
    }

    std::ostream& operator<<(std::ostream& o, const Color4& color) {
        o << "(" << static_cast<int>(color.r) << ", " << static_cast<int>(color.g) << ", " << static_cast<int>(color.b) << ", " << static_cast<int>(color.a) << ")";
        return o;
    }
}
