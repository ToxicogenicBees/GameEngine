/*
    RandomGenerator.hpp

    Declaration of a random minesweeper board generator.
*/

#pragma once

#include "Minesweeper/Generators/BoardGenerator.hpp"
#include <cstdint>

struct RandomGenerator : public BoardGenerator {
    /**
     * @brief Generates a board from the given parameters.
     * 
     * @param board The board being generated into
     * @param start Optional starting tile to avoid generating mines on
     * @param seed Optional generation seed
     */
    void generate(Board& board, std::optional<Vector2i> start = std::nullopt, std::optional<Seed> seed = std::nullopt) override;
};
