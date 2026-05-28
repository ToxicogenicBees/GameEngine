/*
    BoardGenerator.hpp

    Declaration of an abstract minesweeper board generator.
*/

#pragma once

#include "Minesweeper/Core/Board.hpp"
#include <Types/Vector2.hpp>
#include <optional>
#include <stdint.h>

struct BoardGenerator {
    /**
     * @brief Generates a board with a given size and mine count
     */
    virtual Board generate(const Size& size, size_t mines, std::optional<Vector2i> start) = 0;

    /**
     * @brief Destructor.
     */
    virtual ~BoardGenerator() = default;
};
