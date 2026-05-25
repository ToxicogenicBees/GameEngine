/*
    RandomBoard.cpp

    Implementation for a minesweeper board with randomly placed mines
*/

#include "Minesweeper/Objects/Boards/RandomBoard.hpp"
#include <algorithm>
#include <random>

void RandomBoard::populateMines(size_t mine_count) {
    // Cap mine count to the number of available tiles
    mine_count = std::min(mine_count, (size_t)size_.area());

    // Create a vector of all tile indices
    std::vector<size_t> indices(size_.area());
    std::iota(indices.begin(), indices.end(), 0);

    // Shuffle the indices to randomize mine placement
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(indices.begin(), indices.end(), g);

    // Place mines
    for (size_t i = 0; i < mine_count; ++i)
        tiles_[indices[i]]->setValue(TileValue::MINE);
}
