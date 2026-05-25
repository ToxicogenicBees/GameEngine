/*
    Board.cpp

    Implementation for a minesweeper board
*/

#include "Minesweeper/Objects/Boards/Board.hpp"
#include <unordered_set>
#include <random>
#include <algorithm>

Board::Board()
    : sprite_(addComponent<SpriteComponent>("board.png")) {}

void Board::onInit() {

}

void Board::onUpdate(double dt) {

}

void Board::assignNeighbors_() {
    for (int y = 0; y < size_.height(); ++y) {
        for (int x = 0; x < size_.width(); ++x) {
            // Get the current tile
            auto tile = getTile({x, y});

            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    // Skip the tile itself
                    if (dx == 0 && dy == 0) continue;

                    // Add each valid neighbor
                    auto nx = x + dx;
                    auto ny = y + dy;
                    if (nx < size_.width() && ny < size_.height())
                        tile->addNeighbor(getTile({nx, ny}));
                }
            }
        }
    }
}

Tile* Board::getTile(const Vector2i& position) const {
    int index = position.y * size_.width() + position.x;

    if (index < 0 || index >= tiles_.size())
        return nullptr;
    return tiles_[index];
}

Tile* Board::tileAt(const Vector2i& pixel) const {
    auto grid_pos = pixel / Tile::tileSize();
    if (grid_pos.x < 0 || grid_pos.x >= size_.width() || grid_pos.y < 0 || grid_pos.y >= size_.height())
        return nullptr;
    return getTile(grid_pos);
}

Size Board::size() const {
    return size_;
}

std::vector<Tile*> Board::tiles() const {
    return tiles_;
}
