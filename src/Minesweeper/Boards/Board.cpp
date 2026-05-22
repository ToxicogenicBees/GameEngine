/*
    Board.cpp

    Implementation for a minesweeper board
*/

#include "Minesweeper/Boards/Board.hpp"
#include <unordered_set>
#include <random>
#include <algorithm>

/**
 * @brief Constructor
 * 
 * @param size The size of the board.
 */
Board::Board(const Size& size)
    : size_(size), tiles_(size.area()) 
{
    // Generate empty tiles
    for (size_t i = 0; i < size.area(); ++i) {
        tiles_[i] = std::make_unique<Tile>();

        double x = i % size.width;  // Remainder
        double y = i / size.width;  // Quotient
        tiles_[i]->position = 32.0 * Vector2{x, y};
    }

    // Set neighbors for each tile
    for (int y = 0; y < size.height; ++y) {
        for (int x = 0; x < size.width; ++x) {
            // Get the current tile
            auto tile = getTile({x, y});

            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    // Skip the tile itself
                    if (dx == 0 && dy == 0) continue;

                    // Add each valid neighbor
                    auto nx = x + dx;
                    auto ny = y + dy;
                    if (nx < size.width && ny < size.height)
                        tile->addNeighbor(getTile({nx, ny}));
                }
            }
        }
    }
}

/**
 * @brief Gets the tile at the specified position.
 * 
 * @param x The position of the tile.
 * @return A pointer to the tile at the specified position.
 */
Tile* Board::getTile(const Vector2i& position) const {
    return tiles_[position.y * size_.width + position.x].get();
}

/**
 * @brief Gets the size of the board.
 * 
 * @return The size of the board.
 */
Size Board::size() const {
    return size_;
}

/**
 * @brief Gets the width of the board.
 * 
 * @return The width of the board.
 */
size_t Board::width() const {
    return size_.width;
}

/**
 * @brief Gets the height of the board.
 * 
 * @return The height of the board.
 */
size_t Board::height() const {
    return size_.height;
}

/**
 * @brief Gets an iterator to the beginning of the tiles vector
 * 
 * @return An iterator to the beginning of the tiles vector
 */
Board::Iterator Board::begin() {
    return tiles_.begin();
}

/**
 * @brief Gets a constant iterator to the beginning of the tiles vector
 * 
 * @return A constant iterator to the beginning of the tiles vector
 */
Board::CIterator Board::cbegin() const {
    return tiles_.cbegin();
}

/**
 * @brief Gets a constant iterator to the beginning of the tiles vector
 * 
 * @return A constant iterator to the beginning of the tiles vector
 */
Board::CIterator Board::cbegin() {
    return tiles_.cbegin();
}

/**
 * @brief Gets an iterator to the end of the tiles vector
 * 
 * @return An iterator to the end of the tiles vector
 */
Board::Iterator Board::end() {
    return tiles_.end();
}

/**
 * @brief Gets a constant iterator to the end of the tiles vector
 * 
 * @return A constant iterator to the end of the tiles vector
 */
Board::CIterator Board::cend() const {
    return tiles_.cend();
}

/**
 * @brief Gets a constant iterator to the end of the tiles vector
 * 
 * @return A constant iterator to the end of the tiles vector
 */
Board::CIterator Board::cend() {
    return tiles_.cend();
}
