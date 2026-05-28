/*
    RandomGenerator.cpp

    Implementation of a random minesweeper board generator.
*/

#include "Minesweeper/Generators/RandomGenerator.hpp"
#include "Minesweeper/Core/BitGrid.hpp"
#include <algorithm>
#include <random>

namespace {
    std::vector<Vector2i> blacklist(const Vector2i& tile) {
        std::vector<Vector2i> result;
        for (int x = -1; x <= 1; ++x) {
            for (int y = -1; y <= 1; ++y) {
                result.push_back(tile + Vector2i(x, y));
            }
        }
        return result;
    }
}

BitGrid RandomGenerator::generate(const Size& size, size_t mines, std::optional<Vector2i> start) {
    // Create a bit grid for mines
    BitGrid mine_grid(size);

    // Cap mine count to the number of available tiles
    mines = std::min(mines, size.area());

    // Create a vector of all tile indices
    BitGrid index_grid(size, true);
    if (start) {
        for (int x = -1; x <= 1; ++x) {
            for (int y = -1; y <= 1; ++y) {
                auto index = *start + Vector2i(x, y);

                if (index_grid.contains(index))
                    index_grid.set(index, false);
            }
        }
    }
    std::vector<size_t> indices = index_grid.indices();

    // Shuffle the indices to randomize mine placement
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(indices.begin(), indices.end(), g);

    // Place mines
    for (size_t i = 0; i < mines; ++i)
        mine_grid.set(indices[i], true);

    // Return the mine grid
    return std::move(mine_grid);
}
