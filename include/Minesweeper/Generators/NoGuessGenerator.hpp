/*
    NoGuessGenerator.hpp

    Declaration of a no-guess minesweeper board generator.
*/

#pragma once

#include "Minesweeper/Generators/RandomGenerator.hpp"
#include <cstdint>

struct NoGuessGenerator : public RandomGenerator {
    /**
     * @brief Generates a mine grid with a given size and mine count
     * 
     * @param size The size of the board
     * @param mines The number of mines on the board
     * @param start Optional starting tile to avoid generating mines on
     * @param seed Optional generation seed
     */
    BitGrid generate(const Size& size, size_t mines, std::optional<Vector2i> start, std::optional<Seed> seed) override;
};
