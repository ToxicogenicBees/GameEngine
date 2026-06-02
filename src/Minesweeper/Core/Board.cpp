/*
    Board.cpp

    Implementation for a minesweeper board.
*/

#include "Minesweeper/Core/Board.hpp"
#include "Minesweeper/Core/ConstTileWrapper.hpp"
#include "Minesweeper/Core/TileWrapper.hpp"

Board::Board(const Size& size, size_t mine_count)
    : SIZE_(size),
      MINE_COUNT_(mine_count),
      revealed_(size),
      mines_(size),
      flags_(size)
{}

Board::Board(const BitGrid& mines)
    : SIZE_(mines.size()),
      MINE_COUNT_(mines.count()),
      revealed_(mines.size()),
      mines_(mines),
      flags_(mines.size()) 
{}

void Board::reset() {
    // Reset data fields
    revealed_.fill(false);
    mines_.fill(false);
    flags_.fill(false);
}

void Board::generateAt(BoardGenerator& generator, const Vector2i start_tile) {
    // Generate a new mine layout
    mines_ = std::move(generator.generate(SIZE_, MINE_COUNT_, start_tile, std::nullopt));
}

bool Board::isEmpty() const {
    return mines_.count() == 0;
}

bool Board::contains(const Vector2i& index) const {
    return mines_.contains(index);
}

ConstTileWrapper Board::tile(const Vector2i& index) const {
    if (!contains(index))
        throw std::invalid_argument("Cannot create a wrapper for an invalid tile position");
    return ConstTileWrapper(this, index);
}

TileWrapper Board::tile(const Vector2i& index) {
    if (!contains(index))
        throw std::invalid_argument("Cannot create a wrapper for an invalid tile position");
    return TileWrapper(this, index);
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

bool Board::isFalseFlagged(const Vector2i& index) const {
    return flags_.get(index) && !mines_.get(index);
}

bool Board::isRevealed(const Vector2i& index) const {
    return revealed_.get(index);
}

void Board::flag(const Vector2i& index) {
    if (!isFlagged(index)) {
        flags_.set(index, true);
    }
}

void Board::unflag(const Vector2i& index) {
    if (isFlagged(index)) {
        flags_.set(index, false);
    }
}

void Board::reveal(const Vector2i& index) {
    if (!isRevealed(index) && !isFlagged(index)) {
        revealed_.set(index, true);
        if (!isMine(index) && adjacentMineCount(index) == 0) {
            for (auto neighbor : neighbors(index))
                reveal(neighbor);
        }
    }
}

Size Board::size() const {
    return SIZE_;
}

size_t Board::width() const {
    return SIZE_.width();
}

size_t Board::height() const {
    return SIZE_.height();
}

bool Board::isCleared() const {
    return revealed_ == ~mines_;
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
    return MINE_COUNT_;
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
