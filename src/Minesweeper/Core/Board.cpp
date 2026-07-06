/*
    Board.cpp

    Implementation for a minesweeper board.
*/

#include "Minesweeper/Core/Board.hpp"
#include "Minesweeper/Core/ConstTileWrapper.hpp"
#include "Minesweeper/Core/TileWrapper.hpp"

Board::Board(const BitGrid& mines)
    : revealed_(mines.size()),
      mines_(mines),
      flags_(mines.size()),
      size_(mines.size()),
      mine_count_(mines.count())
{}

Board::Board(Size size, size_t mine_count)
    : revealed_(size),
      mines_(size),
      flags_(size),
      size_(size),
      mine_count_(mine_count)
{}

void Board::setAdjacencyMask(const AdjacencyMask& mask) {
    mask_ = mask;
}

AdjacencyMask Board::adjacencyMask() const {
    return mask_;
}

void Board::setSize(Size size) {
    size_ = size;
}

Size Board::size() const {
    return size_;
}

void Board::setMineGrid(const BitGrid& mines) {
    setMineCount(mines.count());
    setSize(mines.size());
    mines_ = mines;
}

BitGrid Board::mineGrid() const {
    return mines_;
}

void Board::setMineCount(size_t count) {
    mine_count_ = std::min(count, size_.area());
}

size_t Board::mineCount() const {
    return mine_count_;
}

void Board::reset() {
    // Reset data fields
    revealed_.fill(false);
    mines_.fill(false);
    flags_.fill(false);
}

bool Board::contains(Vector2i index) const {
    return mines_.contains(index);
}

ConstTileWrapper Board::tile(Vector2i index) const {
    if (!contains(index))
        throw std::invalid_argument("Cannot create a wrapper for an invalid tile position");
    return ConstTileWrapper(this, index);
}

TileWrapper Board::tile(Vector2i index) {
    if (!contains(index))
        throw std::invalid_argument("Cannot create a wrapper for an invalid tile position");
    return TileWrapper(this, index);
}

std::vector<Vector2i> Board::neighbors(Vector2i index) const {
    std::vector<Vector2i> neighbors;
    for (auto& neighbor : mask_.apply(index)) {
        if (contains(neighbor))
            neighbors.emplace_back(neighbor);
    }
    return std::move(neighbors);
}

uint8_t Board::adjacentMineCount(Vector2i index) const {
    uint8_t count = 0;
    for (auto neighbor : neighbors(index)) {
        if (isMine(neighbor))
            ++count;
    }
    return count;
}

uint8_t Board::adjacentFlagCount(Vector2i index) const {
    uint8_t count = 0;
    for (auto neighbor : neighbors(index)) {
        if (isFlagged(neighbor))
            ++count;
    }
    return count;
};

uint8_t Board::revealedNumber(Vector2i index) const {
    if (!isRevealed(index))
        throw std::invalid_argument("Cannot show revealed number of an unrevealed tile");
    return adjacentMineCount(index);
}

bool Board::isMine(Vector2i index) const {
    return mines_.get(index);
}

bool Board::isFlagged(Vector2i index) const {
    return flags_.get(index);
}

bool Board::isFalseFlagged(Vector2i index) const {
    return flags_.get(index) && !mines_.get(index);
}

bool Board::isRevealed(Vector2i index) const {
    return revealed_.get(index);
}

void Board::flag(Vector2i index) {
    if (!isFlagged(index)) {
        flags_.set(index, true);
    }
}

void Board::unflag(Vector2i index) {
    if (isFlagged(index)) {
        flags_.set(index, false);
    }
}

void Board::reveal(Vector2i index) {
    if (!isRevealed(index) && !isFlagged(index)) {
        revealed_.set(index, true);
        if (!isMine(index) && adjacentMineCount(index) == 0) {
            for (auto neighbor : neighbors(index))
                reveal(neighbor);
        }
    }
}

bool Board::isCleared() const {
    return revealed_ == ~mines_;
}

bool Board::isLost() const {
    auto false_grid = BitGrid(size(), false);
    auto result = revealed_ & mines_;

    return (false_grid != result);
}

bool Board::isEmpty() const {
    return mines_.count() == 0;
}

size_t Board::revealedCount() const {
    return revealed_.count();
}

size_t Board::flagCount() const {
    return flags_.count();
}

BitGrid Board::revealedGrid() const {
    return revealed_;
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

std::ostream& operator<<(std::ostream& o, const Board& board) {
    const int X_END_ROW = board.size().width() - 1;
    const int Y_END_ROW = board.size().height() - 1;
    for (int y = 0; y < board.size().height(); ++y) {
        for (int x = 0; x < board.size().width(); ++x) {
            Vector2i index(x, y);
            int count = board.adjacentMineCount(index);
            if (board.isRevealed(index)) {
                if (board.isMine(index))
                    o << "x";
                else
                    o << count;
            }
            else if (board.isFlagged(index))
                o << "/";
            else
                o << "-";
            o << ((x == X_END_ROW && y != Y_END_ROW) ? "\n" : " ");
        }
    }

    return o;
}
