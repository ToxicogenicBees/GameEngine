/*
    Board.tpp

    Template implementation for a minesweeper board.
*/

#pragma once

#include "Minesweeper/Core/Board.hpp"

template<typename Filter>
std::vector<Vector2i> Board::filterTiles(Filter filter) {
    std::vector<Vector2i> result;
    for (const auto& tile : allTiles()) {
        if (filter(tile))
            result.push_back(tile);
    }
    return result;
}
