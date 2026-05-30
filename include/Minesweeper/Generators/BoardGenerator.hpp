/*
    BoardGenerator.hpp

    Declaration of an abstract minesweeper board generator.
*/

#pragma once

#include "Minesweeper/Core/BitGrid.hpp"
#include <Math/Vector2.hpp>
#include <optional>
#include <stdint.h>

struct BoardGenerator {
    /**
     * @brief Generates a mine grid with a given size and mine count
     * 
     * @param size The size of the board
     * @param mines The number of mines on the board
     * @param start Optional starting tile to avoid generating mines on
     * @param seed Optional generation seed
     */
    virtual BitGrid generate(const Size& size, size_t mines, std::optional<Vector2i> start, std::optional<uint64_t> seed) = 0;

    /**
     * @brief Destructor.
     */
    virtual ~BoardGenerator() = default;
};
