/*
    Guid.vpp

    Implementation for a simple GUID class
*/

#include "Types/Guid.hpp"
#include <functional>
#include <iomanip>
#include <sstream>
#include <random>

Guid::Guid() 
    : bytes_(16, 0x00)
{
    std::random_device rd;
    std::mt19937 g(rd());
    
    for (auto& byte : bytes_)
        byte = g() % 256;
}

const std::vector<uint8_t>& Guid::bytes() const {
    return bytes_;
}

std::string Guid::get() const {
    std::stringstream hex;
    hex << std::hex << std::setfill('0');

    hex << (int)bytes_[0] << (int)bytes_[1] << (int)bytes_[2] << (int)bytes_[3] << '-';
    hex << (int)bytes_[4] << (int)bytes_[5] << '-';
    hex << (int)bytes_[6] << (int)bytes_[7] << '-';
    hex << (int)bytes_[8] << (int)bytes_[9] << '-';
    hex << (int)bytes_[10] << (int)bytes_[11] << (int)bytes_[12] << (int)bytes_[13] << (int)bytes_[14] << (int)bytes_[15];

    return hex.str();
}
