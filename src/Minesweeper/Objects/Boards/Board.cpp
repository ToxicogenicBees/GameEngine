/*
    Board.cpp

    Implementation for a minesweeper board
*/

#include "Minesweeper/Objects/Boards/Board.hpp"
#include <unordered_set>
#include <random>
#include <algorithm>

void Board::assignNeighbors_() {
    for (int y = 0; y < (int)size_.height(); ++y) {
        for (int x = 0; x < (int)size_.width(); ++x) {
            // Get the current tile
            auto tile = getTile({x, y});

            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    // Skip the tile itself
                    if (dx == 0 && dy == 0) continue;

                    // Add each valid neighbor
                    auto nx = x + dx;
                    auto ny = y + dy;
                    if (nx >= 0 && nx < (int)size_.width() && ny >= 0 && ny < (int)size_.height())
                        tile->addNeighbor(getTile({nx, ny}));
                }
            }
        }
    }
}

void Board::onInit() {

}

void Board::onUpdate(double dt) {

}

Board::Board()
    : sprite_(addComponent<SpriteComponent>("board.png")) {}

Tile* Board::getTile(const Vector2i& position) const {
    int index = position.y * size_.width() + position.x;

    if (index < 0 || index >= tiles_.size())
        return nullptr;
    return tiles_[index];
}

Tile* Board::tileAt(const Vector2i& pixel) const {
    auto world_pos = scene()->camera().screenToWorld(pixel);

    for (Tile* tile : tiles_) {
        if (tile->getComponent<BoxCollider2D>()->contains(world_pos))
            return tile;
    }

    return nullptr;
}

Size Board::size() const {
    return size_;
}

bool Board::isCleared() const {
    for (auto& tile : tiles_) {
        if (!tile->isMine() && !tile->isRevealed())
            return false;
    } 
    return true;
}

bool Board::isLost() const {
    for (auto& tile : tiles_) {
        if (tile->isMine() && tile->isRevealed())
            return true;
    } 
    return false;
}

void Board::expose() {
    for (auto& tile : tiles_)
        tile->expose();
}

std::vector<Tile*> Board::tiles() const {
    return tiles_;
}

/**
 * @brief Gets the mine count of the board.
 * 
 * @return The mine count of the board.
 */
size_t Board::mineCount() const {
    return mine_count_;
}

/**
 * @brief Gets the flag count of the board.
 * 
 * @return The flag count of the board.
 */
size_t Board::flagCount() const {
    size_t count = 0;
    for (auto& tile : tiles_) {
        if (tile->isFlagged())
            ++count;
    }
    return count;
}
