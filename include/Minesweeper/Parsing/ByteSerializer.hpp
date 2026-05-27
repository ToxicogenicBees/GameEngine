/*
    ByteSerializer.hpp

    Declaration for a serializer, converting a minesweeper board to/from byte string data.
*/

#pragma once

#include "Minesweeper/Core/Board.hpp"
#include <string>

class ByteSerializer {
private:
    /**
     * @brief Constructor. (deleted)
     */
    ByteSerializer() = delete;

public:
    /**
     * @brief Convert board state to string data.
     * 
     * @param board The raw board state.
     * @return The corresponding debug string.
     */
    static std::string toString(const Board& board);
    /**
     * @brief Convert string data to board state.
     * 
     * @param data The raw byte string data.
     * @return The corresponding board state.
     */
    static Board toBoard(const std::string& data);
};
