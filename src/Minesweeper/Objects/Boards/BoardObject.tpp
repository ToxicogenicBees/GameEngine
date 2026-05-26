/*
    BoardObject.tpp

    Template implementation for a minesweeper board
*/

#pragma once

#include "Minesweeper/Objects/Boards/BoardObject.hpp"

template <typename Creator, typename Destroyer>
void BoardObject::populateTiles_(const Size& size, Creator tile_creator, Destroyer tile_destroyer) {
    // Destroy old tiles
    for (auto& tile : tiles_)
        tile_destroyer(std::move(tiles_.back()));
    tiles_.clear();

    // Create new tiles
    for (size_t i = 0; i < (int)size_.area(); ++i)
        tiles_.push_back(std::move(tile_creator()));

    // Set tile positions
    for (size_t x = 0; x < (int)size_.width(); ++x) {
        for (size_t y = 0; y < (int)size_.height(); ++y) {
            auto tile = getTile({(int)x, (int)y});
            tile->transform().position = {
                (double)TileObject::tileSize() * x,
                (double)TileObject::tileSize() * y
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
void BoardObject::generate(const Size& size, size_t mine_count, Creator tile_creator, Destroyer tile_destroyer) {
    // Update size and mine count
    mine_count_ = mine_count;
    size_ = size;

    // Populate the board with tiles
    populateTiles_(size, tile_creator, tile_destroyer);

    // Populate the board with mines
    populateMines(mine_count);

    // Update tile values
    for (auto& tile : tiles_)
        tile->setValue(tile->isMine() ? TileValue::MINE : (TileValue)tile->mineCount());
}
