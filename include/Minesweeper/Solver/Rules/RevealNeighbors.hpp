/*
    RevealNeighbors.hpp

    Declaration for a rule that reveals neighboring tiles when applicable.
*/

#pragma once

#include "Minesweeper/Solver/Rules/Rule.hpp"

class RevealNeighbors : public Rule {
public:
    /**
     * @brief Constructor.
     */
    RevealNeighbors() = default;

    /**
     * @brief Applies the rule to a board.
     * 
     * @return A sequence of moves that forwards the board state.
     */
    void apply(const SolverState& states, std::vector<Move>& out) const override;
};
