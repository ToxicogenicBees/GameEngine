/*
    NoGuessGenerator.cpp

    Implementation of a no-guess minesweeper board generator.
*/

#include "Minesweeper/Generators/NoGuessGenerator.hpp"
#include "Minesweeper/Solver/Rules/SingleCellConstraintResolution.hpp"
#include "Minesweeper/Solver/Solver.hpp"
#include "Minesweeper/Core/BitGrid.hpp"
#include <algorithm>
#include <random>

void NoGuessGenerator::generate(Board& board, std::optional<Vector2i> start, std::optional<Seed> seed) {
    // Create a bit grid for mines
    // Generate a random mine grid using the random generator
    RandomGenerator::generate(board, start, seed);

    // Validate the generated grid with a solver, regenerating if the grid is unsolvable
    Solver solver;
    solver.addRule(std::make_unique<SingleCellConstraintResolution>());

    while (true) {
        auto result = solver.solve(board.mineGrid(), start.value_or(Vector2i(0, 0)));
        if (result)
            break;

        // Regenerate the grid if the solver fails
        Seed new_seed = seed ? Seed(seed->value() + 1) : Seed();
        RandomGenerator::generate(board, start, new_seed);
    }
}
