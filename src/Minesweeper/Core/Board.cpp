/*
    Board.cpp

    Implementation for a minesweeper board.
*/

#include "Minesweeper/Core/Board.hpp"
#include <iostream>

Board::Board(const Size& size)
    : revealed_(size), mines_(size), flags_(size) {}

Board::Board(const BitGrid& mines)
    : revealed_(mines.size()), mines_(mines), flags_(mines.size()) {}

bool Board::contains(const Vector2i& index) const {
    return mines_.contains(index);
}

std::vector<Vector2i> Board::neighbors(const Vector2i& index) const {
    std::vector<Vector2i> n;
    for (int x = -1; x <= 1; ++x) {
        for (int y = -1; y <= 1; ++y) {
            if (x == 0 && y == 0)
                continue;
            
            auto pos = index + Vector2i{x, y};
            if (contains(pos))
                n.push_back(pos);
        }
    }
    return n;
}

uint8_t Board::adjacentMineCount(const Vector2i& index) const {
    uint8_t count = 0;
    for (auto neighbor : neighbors(index)) {
        if (isMine(neighbor))
            ++count;
    }
    return count;
}

uint8_t Board::adjacentFlagCount(const Vector2i& index) const {
    uint8_t count = 0;
    for (auto neighbor : neighbors(index)) {
        if (isFlagged(neighbor))
            ++count;
    }
    return count;
};

uint8_t Board::revealedNumber(const Vector2i& index) const {
    if (!isRevealed(index))
        throw std::invalid_argument("Cannot show revealed number of an unrevealed tile");
    return adjacentMineCount(index);
}

bool Board::isMine(const Vector2i& index) const {
    return mines_.get(index);
}

bool Board::isFlagged(const Vector2i& index) const {
    return flags_.get(index);
}

bool Board::isRevealed(const Vector2i& index) const {
    return revealed_.get(index);
}

void Board::flag(const Vector2i& index) {
    flags_.set(index, true);
}

void Board::unflag(const Vector2i& index) {
    flags_.set(index, false);
}

void Board::reveal(const Vector2i& index) {
    if (!isRevealed(index)) {
        revealed_.set(index, true);
        if (!isMine(index) && adjacentMineCount(index) == 0) {
            for (auto neighbor : neighbors(index))
                reveal(neighbor);
        }
    }
}

void Board::setSize(const Size& size) {
    revealed_.setSize(size);
    flags_.setSize(size);
    mines_.setSize(size);
}

Size Board::size() const {
    return mines_.size();
}

size_t Board::width() const {
    return mines_.size().width();
}

size_t Board::height() const {
    return mines_.size().height();
}

bool Board::isCleared() const {
    auto true_grid = BitGrid(size(), true);
    auto result = revealed_ ^ mines_;

    return result == true_grid;
}

bool Board::isLost() const {
    auto false_grid = BitGrid(size(), false);
    auto result = revealed_ & mines_;

    return (false_grid != result);
}

size_t Board::revealedCount() const {
    return revealed_.count();
}

size_t Board::mineCount() const {
    return mines_.count();
}

size_t Board::flagCount() const {
    return flags_.count();
}

BitGrid Board::revealedGrid() const {
    return revealed_;
}

BitGrid Board::mineGrid() const {
    return mines_;
}

BitGrid Board::flagGrid() const {
    return flags_;
}

std::vector<Vector2i> Board::allTiles() const {
    std::vector<Vector2i> indexes;
    for (int y = 0; y < size().height(); ++y)
        for (int x = 0; x < size().width(); ++x)
            indexes.push_back({x, y});
    return indexes;
}
