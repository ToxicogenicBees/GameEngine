/*
    BoardGenerator.hpp

    Declaration of an abstract minesweeper board generator.
*/

#pragma once

#include "Minesweeper/Core/Board.hpp"
#include <Utility/Seed.hpp>
#include <Math/Vector2.hpp>
#include <optional>
#include <cstdint>

struct BoardGenerator {
    /**
     * @brief Generates a board from the given parameters.
     * 
     * @param board The board being generated into
     * @param start Optional starting tile to avoid generating mines on
     * @param seed Optional generation seed
     */
    virtual void generate(Board& board, std::optional<Vector2i> start = std::nullopt, std::optional<Seed> seed = std::nullopt) = 0;

    /**
     * @brief Destructor.
     */
    virtual ~BoardGenerator() = default;
};
