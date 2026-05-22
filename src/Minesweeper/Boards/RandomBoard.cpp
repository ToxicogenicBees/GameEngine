/*
    RandomBoard.cpp

    Implementation for a minesweeper board with randomly placed mines
*/

#include "Minesweeper/Boards/RandomBoard.hpp"
#include <algorithm>
#include <random>

/**
 * @brief Constructor
 * 
 * @param size The size of the board.
 */
RandomBoard::RandomBoard(const Size& size)
    : Board(size) {}

/**
 * @brief Generates the board with the desired number of mines.
 * 
 * @param mine_count The number of mines to be placed on the board.
 */
void RandomBoard::generate(size_t mine_count) {
    // Cap mine count to the number of available tiles
    mine_count = std::min(mine_count, size_.area());

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
    
    // Update tile values based on neighboring mines
    for (auto& tile : tiles_)
        tile->setValue(tile->isMine() ? TileValue::MINE : (TileValue)tile->mineCount());
}
