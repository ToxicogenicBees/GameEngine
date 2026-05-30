/*
    Solver.hpp

    Declaration of a minesweeper board solver.
*/

#pragma once

#include "Minesweeper/Solver/Move.hpp"
#include "Minesweeper/Solver/Rule.hpp"
#include "Minesweeper/Core/Board.hpp"
#include <Math/Vector2.hpp>
#include <vector>
#include <memory>

class Solver {
private:
    const bool DEBUG_LOG_;
    std::vector<std::unique_ptr<Rule>> rules_;

    /**
     * @brief Applies the given moves to the given board.
     * 
     * @param board The board being applied to
     * @param moves The moves being applied
     * @return If any progress was made
     */
    bool applyMoves_(Board& board, const std::vector<Move>& moves);

public:
    /**
     * @brief Constructor.
     */
    Solver(bool show_debug = false);

    /**
     * @brief Add a rule to the solver.
     * 
     * @param rule The rule being added.
     */
    void addRule(std::unique_ptr<Rule> rule);

    /**
     * @brief Attempts to solve a given minesweeper mine grid.
     * 
     * @param mines The mine grid to solve.
     * @param initial_tile The initial tile revealed.
     * @return If the board was successfully able to be solve.
     */
    bool solve(const BitGrid& mines, const Vector2i& initial_tile);
};
