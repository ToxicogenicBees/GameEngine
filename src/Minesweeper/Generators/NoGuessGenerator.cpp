/*
    NoGuessGenerator.cpp

    Implementation of a no-guess minesweeper board generator.
*/

#include "Minesweeper/Generators/NoGuessGenerator.hpp"
#include "Minesweeper/Solver/Rules/RevealNeighbors.hpp"
#include "Minesweeper/Solver/Rules/FlagNeighbors.hpp"
#include "Minesweeper/Solver/Solver.hpp"
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

BitGrid NoGuessGenerator::generate(const Size& size, size_t mines, std::optional<Vector2i> start, std::optional<uint64_t> seed) {
    // Create a bit grid for mines
    BitGrid mine_grid(size);

    // Generate a random mine grid using the random generator
    mine_grid = RandomGenerator::generate(size, mines, start, seed);

    // Validate the generated grid with a solver, regenerating if the grid is unsolvable
    Solver solver;
    solver.addRule(std::make_unique<RevealNeighbors>());
    solver.addRule(std::make_unique<FlagNeighbors>());

    while (true) {
        auto result = solver.solve(mine_grid, start.value_or(Vector2i(0, 0)));
        if (result)
            break;

        // Regenerate the grid if the solver has to guess
        uint64_t new_seed = seed ? seed.value() + 1 : std::random_device{}();
        if (seed)
            ++(*seed);
        mine_grid = RandomGenerator::generate(size, mines, start, seed);
    }

    // Return the mine grid
    return std::move(mine_grid);
}
