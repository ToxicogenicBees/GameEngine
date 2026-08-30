/*
    Guid.cpp

    Implementation for a simple GUID class
*/

#include "core/utility/random/Guid.hpp"
#include <iomanip>
#include <sstream>

namespace toxico {
    Guid::Guid()
        : high_(random_generator_.next<uint64_t>()),
          low_(random_generator_.next<uint64_t>())
    {}

    std::size_t Guid::getHash() const noexcept {
        return static_cast<std::size_t>(high_ ^ low_);
    };

    bool Guid::operator==(const Guid& other) const {
        return high_ == other.high_ && low_ == other.low_;
    }

    std::string Guid::toString() const noexcept {
        std::stringstream hex;

        auto output_range = [&hex, this](std::size_t start, std::size_t end) {
            for (std::size_t i = start; i <= end; ++i) {
                uint64_t chunk = (i < 8) ? high_ : low_;
                std::size_t bit_offset = (7 - (i & 7)) * 8;
                uint8_t byte = static_cast<uint8_t>(chunk >> bit_offset);

                hex << std::hex
                    << std::setw(2)
                    << std::setfill('0')
                    << static_cast<int>(byte);
            }
        };

        output_range(0, 3);
        hex << "-";
        output_range(4, 5);
        hex << "-";
        output_range(6, 7);
        hex << "-";
        output_range(8, 9);
        hex << "-";
        output_range(10, 15);

        return hex.str();
    }
}
