/*
    Guid.vpp

    Implementation for a simple GUID class
*/

#include "Core/Guid.hpp"
#include <functional>
#include <iomanip>
#include <sstream>
#include <random>

Guid::Guid() 
    : bytes_(16, 0x00)
{
    for (auto& byte : bytes_)
        byte = std::rand() % 256;
}

const std::vector<uint8_t>& Guid::bytes() const {
    return bytes_;
}

Guid::operator std::string() const {
    std::stringstream hex;
    hex << std::hex << std::setfill('0');

    hex << bytes_[0] << bytes_[1] << bytes_[2] << bytes_[3] << '-';
    hex << bytes_[4] << bytes_[5] << '-';
    hex << bytes_[6] << bytes_[7] << '-';
    hex << bytes_[8] << bytes_[9] << '-';
    hex << bytes_[10] << bytes_[11] << bytes_[12] << bytes_[13] << bytes_[14] << bytes_[15];

    return hex.str();
}
