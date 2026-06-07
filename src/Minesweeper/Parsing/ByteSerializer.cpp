/*
    DebugSerializer.hpp

    Declaration for a serializer, converting a minesweeper board to/from byte string data.
*/

#include "Minesweeper/Parsing/ByteSerializer.hpp"
#include "Minesweeper/Core/BitGrid.hpp"
#include <iomanip>
#include <sstream>

namespace {
    uint8_t hexToInt(char hex_digit) {
        if (hex_digit >= 'a')
            return (10 + hex_digit - 'a');
        return (hex_digit - '0');
    }
}

std::string ByteSerializer::toString(const Board& board) {
    // Create hex string stream
    std::stringstream hex;

    // Store width info
    hex << static_cast<int>(board.size().width());
    hex << 'x';
    hex << static_cast<int>(board.size().height());
    hex << ':';

    // Convert mine data to hex
    auto mines = board.mineGrid();
    for (auto byte : mines.bytes())
        hex << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);

    // Return string data
    return hex.str();
}

Board ByteSerializer::toBoard(const std::string& data) {
    std::stringstream hex;
    hex << data;

    std::string s;
    char c;

    // Fetch board width
    size_t width;
    while (hex >> c) {
        if (c == 'x')
            break;
        s += c;
    }
    width = std::stoi(s);
    s = "";

    // Fetch board height
    size_t height;
    while (hex >> c) {
        if (c == ':')
            break;
        s += c;
    }
    height = std::stoi(s);
    s = "";

    // Fetch binary
    std::vector<std::byte> bytes;
    bool parity = true;
    while (hex >> c) {
        int val = hexToInt(c);
        if (parity)
            bytes.push_back(std::byte(val));
        else {
            bytes.back() <<= 4;
            bytes.back() |= std::byte(val);
        }

        parity = !parity;
    }

    BitGrid mines({width, height}, bytes);
    return Board(mines);
}
