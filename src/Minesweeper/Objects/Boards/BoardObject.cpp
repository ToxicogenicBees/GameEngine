/*
    BoardObject.cpp

    Implementation for a minesweeper board
*/

#include "Minesweeper/Objects/Boards/BoardObject.hpp"
#include <unordered_set>
#include <random>
#include <algorithm>

void BoardObject::assignNeighbors_() {
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

void BoardObject::onInit() {

}

void BoardObject::onUpdate(double dt) {

}

BoardObject::BoardObject()
    : sprite_(addComponent<SpriteComponent>("board.png")) {}

TileObject* BoardObject::getTile(const Vector2i& position) const {
    int index = position.y * size_.width() + position.x;

    if (index < 0 || index >= tiles_.size())
        return nullptr;
    return tiles_[index];
}

TileObject* BoardObject::tileAt(const Vector2i& pixel) const {
    auto world_pos = scene()->camera().screenToWorld(pixel);

    for (auto& tile : tiles_) {
        if (tile->getComponent<BoxCollider2D>()->contains(world_pos))
            return tile;
    }

    return nullptr;
}

Size BoardObject::size() const {
    return size_;
}

bool BoardObject::isCleared() const {
    for (auto& tile : tiles_) {
        if (!tile->isMine() && !tile->isRevealed())
            return false;
    } 
    return true;
}

bool BoardObject::isLost() const {
    for (auto& tile : tiles_) {
        if (tile->isMine() && tile->isRevealed())
            return true;
    } 
    return false;
}

void BoardObject::expose() {
    for (auto& tile : tiles_)
        tile->expose();
}

std::vector<TileObject*> BoardObject::tiles() const {
    return tiles_;
}

size_t BoardObject::mineCount() const {
    return mine_count_;
}

size_t BoardObject::flagCount() const {
    size_t count = 0;
    for (auto& tile : tiles_) {
        if (tile->isFlagged())
            ++count;
    }
    return count;
}
