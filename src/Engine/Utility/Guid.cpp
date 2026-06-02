/*
    Guid.vpp

    Implementation for a simple GUID class
*/

#include "Utility/Guid.hpp"
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <random>

Guid::Guid()
    : bytes_(16, 0x00)
{
    for (auto& byte : bytes_)
        byte = random_generator_.next<uint8_t>();
}

const std::vector<uint8_t>& Guid::bytes() const {
    return bytes_;
}

std::string Guid::get() const {
    std::stringstream hex;

    auto output_range = [&hex, this](size_t start, size_t end) {
        for (size_t i = start; i <= end; ++i)
            hex << std::hex << std::setfill('0') << std::setw(2) << (int)(bytes_[i]);
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
