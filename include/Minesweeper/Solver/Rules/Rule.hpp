/*
    Rule.hpp

    Declaration for an abstract minesweeper rule
*/

#pragma once

#include "Minesweeper/Solver/SolverState.hpp"
#include "Minesweeper/Solver/Move.hpp"
#include <vector>

class Rule {
private:

public:
    /**
     * @brief Constructor.
     */
    Rule() = default;
    
    /**
     * @brief Applies the rule to a board.
     * 
     * @return A sequence of moves that forwards the board state.
     */
    virtual void apply(const SolverState& states, std::vector<Move>& out) const = 0;

    /**
     * @brief Destructor.
     */
    virtual ~Rule() = default;
};
