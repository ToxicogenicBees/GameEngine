/*
    RandomBoard.hpp

    Declaration for a minesweeper board with randomly placed mines
*/

#pragma once

#include "Minesweeper/Boards/Board.hpp"
#include "Types/Size.hpp"

class RandomBoard : public Board {
public:
    /**
     * @brief Constructor
     * 
     * @param size The size of the board.
     */
    RandomBoard(const Size& size);

    /**
     * @brief Generates the board with the desired number of mines.
     * 
     * @param mine_count The number of mines to be placed on the board.
     */
    void generate(size_t mine_count) override;
};
