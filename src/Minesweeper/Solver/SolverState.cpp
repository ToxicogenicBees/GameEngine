/*
    SolverState.cpp

    Implementation of a class containing the current state of a minesweeper solver
*/

#include "Minesweeper/Solver/SolverState.hpp"
#include <algorithm>

SolverState::SolverState(const Board& board) 
    : board_(&board),
      revealed_(board.revealedGrid()),
      flagged_(board.flagGrid()),
      unknown_((~revealed_) & (~flagged_)),
      frontier_(unknown_ & adjacentTo(revealed_)),
      constraints_(revealed_ & adjacentTo(frontier_))
{}

bool SolverState::isUnknown(const Vector2i& tile) const {
    return unknown_.get(tile);
}

bool SolverState::isFrontier(const Vector2i& tile) const {
    return frontier_.get(tile);
}

bool SolverState::isRevealed(const Vector2i& tile) const {
    return revealed_.get(tile);
}

bool SolverState::isFlagged(const Vector2i& tile) const {
    return flagged_.get(tile);
}

std::vector<Vector2i> SolverState::revealedTiles() const {
    return revealed_.positions();
}

std::vector<Vector2i> SolverState::flaggedTiles() const {
    return flagged_.positions();
}

std::vector<Vector2i> SolverState::unknownTiles() const {
    return unknown_.positions();
}

std::vector<Vector2i> SolverState::frontierTiles() const {
    return frontier_.positions();
}

std::vector<Vector2i> SolverState::constraintTiles() const {
    return constraints_.positions();
}

BitGrid SolverState::adjacentTo(const BitGrid& grid) const {
    BitGrid adjacence(grid.size());
    for (size_t tile = 0; tile < grid.size().area(); ++tile) {
        if (!grid.get(tile))
            continue;

        int x = tile % grid.size().width();
        int y = tile / grid.size().width();
        for (auto neighbor : neighbors({x, y}))
            adjacence.set(neighbor, true);
    }
    return adjacence;
}

uint8_t SolverState::adjacentFlagCount(const Vector2i& tile) const {
    uint8_t count = 0;
    for (auto neighbor : neighbors(tile)) {
        if (isFlagged(neighbor))
            ++count;
    }
    return count;
}

uint8_t SolverState::adjacentUnknownCount(const Vector2i& tile) const {
    uint8_t count = 0;
    for (auto neighbor : neighbors(tile)) {
        if (isUnknown(neighbor))
            ++count;
    }
    return count;
}

uint8_t SolverState::revealedNumber(const Vector2i& tile) const {
    return board_->revealedNumber(tile);
}

std::vector<Vector2i> SolverState::neighbors(const Vector2i& tile) const {
    return board_->neighbors(tile);
}
