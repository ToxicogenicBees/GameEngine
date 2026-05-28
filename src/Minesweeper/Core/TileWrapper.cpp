/*
    TileWrapper.hpp

    Implementation of a wrapper class that wraps a minesweeper board's operations around a specific index.
*/

#include "Minesweeper/Core/TileWrapper.hpp"

TileWrapper::TileWrapper(Board* const board, const Vector2i& index)
    : INDEX_(index), board_(board) {}

std::vector<TileWrapper> TileWrapper::neighbors() const {
    // Fetch neighbor indices
    auto neighbor_indices = board_->neighbors(INDEX_);

    // Wrap indices in a tile wrapper
    std::vector<TileWrapper> result;
    for (const auto& index : neighbor_indices)
        result.push_back(TileWrapper(board_, index));
    return result;
}

uint8_t TileWrapper::adjacentMineCount() const {
    return board_->adjacentMineCount(INDEX_);
}

uint8_t TileWrapper::adjacentFlagCount() const {
    return board_->adjacentFlagCount(INDEX_);
}

uint8_t TileWrapper::revealedNumber() const {
    return board_->revealedNumber(INDEX_);
}

bool TileWrapper::isMine() const {
    return board_->isMine(INDEX_);
}

bool TileWrapper::isFlagged() const {
    return board_->isFlagged(INDEX_);
}

bool TileWrapper::isRevealed() const {
    return board_->isRevealed(INDEX_);
}

bool TileWrapper::isFalseFlagged() const {
    return board_->isFalseFlagged(INDEX_);
}

void TileWrapper::flag() {
    board_->flag(INDEX_);
}

void TileWrapper::unflag() {
    board_->unflag(INDEX_);
}

void TileWrapper::reveal() {
    board_->reveal(INDEX_);
}

Vector2i TileWrapper::index() const {
    return INDEX_;
}

Board* const TileWrapper::board() {
    return board_;
}
