/*
    Board.cpp

    Implementation for a minesweeper board
*/

#include "Minesweeper/Boards/Board.hpp"
#include <unordered_set>
#include <random>
#include <algorithm>

namespace {
    constexpr int TILE_SIZE = 32;
}

Board::Board(const Size& size)
    : size_(size), tiles_(size.area()) {}

Tile* Board::getTile(const Vector2i& position) const {
    int index = position.y * size_.width + position.x;

    if (index < 0 || index >= tiles_.size())
        return nullptr;
    return tiles_[index];
}

Tile* Board::tileAt(const Vector2i& pixel) const {
    auto grid_pos = pixel / TILE_SIZE;
    if (grid_pos.x < 0 || grid_pos.x >= width() || grid_pos.y < 0 || grid_pos.y >= height())
        return nullptr;
    return getTile(grid_pos);
}

Size Board::size() const {
    return size_;
}

size_t Board::width() const {
    return size_.width;
}

size_t Board::height() const {
    return size_.height;
}

void Board::generate(size_t mine_count, std::function<Tile*()> tile_factory) {
    // Generate tiles
    for (size_t i = 0; i < size_.area(); ++i) {
        tiles_[i] = tile_factory();

        double x = i % size_.width;  // Remainder
        double y = i / size_.width;  // Quotient
        tiles_[i]->transform().position = TILE_SIZE * Vector2{x, y};
    }

    // Set neighbors for each tile
    for (int y = 0; y < size_.height; ++y) {
        for (int x = 0; x < size_.width; ++x) {
            // Get the current tile
            auto tile = getTile({x, y});

            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    // Skip the tile itself
                    if (dx == 0 && dy == 0) continue;

                    // Add each valid neighbor
                    auto nx = x + dx;
                    auto ny = y + dy;
                    if (nx < size_.width && ny < size_.height)
                        tile->addNeighbor(getTile({nx, ny}));
                }
            }
        }
    }

    // Populate the board with mines
    populateMines(mine_count);
}

Board::Iterator Board::begin() {
    return tiles_.begin();
}

Board::CIterator Board::cbegin() const {
    return tiles_.cbegin();
}

Board::CIterator Board::cbegin() {
    return tiles_.cbegin();
}

Board::Iterator Board::end() {
    return tiles_.end();
}

Board::CIterator Board::cend() const {
    return tiles_.cend();
}

Board::CIterator Board::cend() {
    return tiles_.cend();
}
