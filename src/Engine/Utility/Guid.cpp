/*
    Guid.vpp

    Implementation for a simple GUID class
*/

#include "Utility/Guid.hpp"
#include <iomanip>
#include <sstream>

Guid::Guid()
    : high_(random_generator_.next<uint64_t>()),
      low_(random_generator_.next<uint64_t>())
{}

std::pair<uint64_t, uint64_t> Guid::bytes() const {
    return {high_, low_};
}

std::string Guid::get() const {
    std::stringstream hex;

    auto output_range = [&hex, this](size_t start, size_t end) {
        for (size_t i = start; i <= end; ++i) {
            uint64_t chunk = (i < 8) ? high_ : low_;
            size_t bit_offset = (7 - (i & 7)) * 8;
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

namespace std {
    size_t hash<Guid>::operator()(const Guid& guid) const noexcept {
        auto bytes = guid.bytes();
        uint64_t value = bytes.first ^ bytes.second;
        return std::hash<uint64_t>{}(value);
    }
}
