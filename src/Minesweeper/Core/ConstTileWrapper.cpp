/*
    ConstTileWrapper.hpp

    Implementation of a wrapper class that wraps a minesweeper board's operations around a specific index.
*/

#include "Minesweeper/Core/ConstTileWrapper.hpp"

ConstTileWrapper::ConstTileWrapper(const Board* const board, const Vector2i& index)
    : INDEX_(index), board_(board) {}

std::vector<ConstTileWrapper> ConstTileWrapper::neighbors() const {
    // Fetch neighbor indices
    auto neighbor_indices = board_->neighbors(INDEX_);

    // Wrap indices in a tile wrapper
    std::vector<ConstTileWrapper> result;
    for (const auto& index : neighbor_indices)
        result.push_back(ConstTileWrapper(board_, index));
    return result;
}

uint8_t ConstTileWrapper::adjacentMineCount() const {
    return board_->adjacentMineCount(INDEX_);
}

uint8_t ConstTileWrapper::adjacentFlagCount() const {
    return board_->adjacentFlagCount(INDEX_);
}

uint8_t ConstTileWrapper::revealedNumber() const {
    return board_->revealedNumber(INDEX_);
}

bool ConstTileWrapper::isMine() const {
    return board_->isMine(INDEX_);
}

bool ConstTileWrapper::isFlagged() const {
    return board_->isFlagged(INDEX_);
}

bool ConstTileWrapper::isFalseFlagged() const {
    return board_->isFalseFlagged(INDEX_);
}

bool ConstTileWrapper::isRevealed() const {
    return board_->isRevealed(INDEX_);
}

Vector2i ConstTileWrapper::index() const {
    return INDEX_;
}

const Board* const ConstTileWrapper::board() const {
    return board_;
}
