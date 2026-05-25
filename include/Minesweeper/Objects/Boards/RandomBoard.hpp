/*
    RandomBoard.hpp

    Declaration for a minesweeper board with randomly placed mines
*/

#pragma once

#include "Minesweeper/Objects/Boards/Board.hpp"
#include "Types/Size.hpp"

class RandomBoard : public Board {
protected:
    /**
     * @brief Assign a certain number of tiles to be mines
     * 
     * @param mine_count The number of mines to be placed on the board.
     */
    void populateMines(size_t mine_count) override;

public:
    /**
     * @brief Constructor
     */
    RandomBoard() = default;
};
