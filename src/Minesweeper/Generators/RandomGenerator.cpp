/*
    RandomGenerator.cpp

    Implementation of a random minesweeper board generator.
*/

#include "Minesweeper/Generators/RandomGenerator.hpp"
#include "Minesweeper/Core/BitGrid.hpp"
#include <Utility/Random.hpp>
#include <algorithm>
#include <random>
#include <iostream>

namespace {
    std::vector<Vector2i> blacklist(Vector2i tile) {
        std::vector<Vector2i> result;
        for (int x = -1; x <= 1; ++x) {
            for (int y = -1; y <= 1; ++y) {
                result.push_back(tile + Vector2i(x, y));
            }
        }
        return result;
    }
}

void RandomGenerator::generate(Board& board, std::optional<Vector2i> start, std::optional<Seed> seed) {
    // Create list of blacklisted indices
    std::vector<Vector2i> blacklist;
    if (start) {
        blacklist = board.neighbors(*start);
        blacklist.emplace_back(*start);
    }

    // Create a vector of all allowed tile indices
    std::vector<Vector2i> indices;
    auto size = board.size();
    for (int y = 0; y < size.height(); ++y) {
        for (int x = 0; x < size.width(); ++x) {
            auto index = Vector2i(x, y);
            if (std::find(blacklist.begin(), blacklist.end(), index) == blacklist.end())
                indices.push_back(index);
        }
    }

    // Shuffle the indices to randomize mine placement
    Random random(seed.value_or(Seed()));
    random.shuffle(indices.begin(), indices.end());

    // Place mines
    auto mine_count = std::min(board.mineCount(), indices.size());
    BitGrid mine_grid(size);
    for (size_t i = 0; i < mine_count; ++i)
        mine_grid.set(indices[i], true);

    // Apply the mine grid
    board.setMineGrid(std::move(mine_grid));
}
