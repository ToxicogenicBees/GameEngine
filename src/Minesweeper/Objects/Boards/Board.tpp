/*
    Board.tpp

    Template implementation for a minesweeper board
*/

#pragma once

#include "Minesweeper/Objects/Boards/Board.hpp"

template <typename Creator, typename Destroyer>
void Board::populateTiles_(const Size& size, Creator tile_creator, Destroyer tile_destroyer) {
    // Update size
    size_ = size;

    // Destroy old tiles
    for (auto& tile : tiles_)
        tile_destroyer(std::move(tiles_.back()));
    tiles_.clear();

    // Create new tiles
    for (size_t i = 0; i < size_.area(); ++i)
        tiles_.push_back(std::move(tile_creator()));

    // Set tile positions
    for (size_t x = 0; x < size_.width(); ++x) {
        for (size_t y = 0; y < size_.height(); ++y) {
            auto tile = getTile({(int)x, (int)y});
            tile->transform().position = {
                (double)Tile::tileSize() * x,
                (double)Tile::tileSize() * y
            };
        }
    }

    // Set tile neighbors
    assignNeighbors_();

    // Initialize tiles
    for (auto& tile : tiles_)
        tile->setState(TileState::HIDDEN);
}

template <typename Creator, typename Destroyer>
void Board::generate(const Size& size, size_t mine_count, Creator tile_creator, Destroyer tile_destroyer) {
    // Populate the board with tiles
    populateTiles_(size, tile_creator, tile_destroyer);

    // Populate the board with mines
    populateMines(mine_count);

    // Update tile values
    for (auto& tile : tiles_)
        tile->setValue(tile->isMine() ? TileValue::MINE : (TileValue)tile->mineCount());
}
