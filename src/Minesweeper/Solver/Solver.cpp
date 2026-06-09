/*
    Solver.hpp

    Declaration of a minesweeper board solver.
*/

#include "Minesweeper/Solver/Solver.hpp"
#include <iostream>

bool Solver::applyMoves_(Board& board, const std::vector<Move>& moves) {
    bool progress = false;

    // Apply moves
    for (const auto& move : moves) {
        if (DEBUG_LOG_)
            std::clog << (move.type == MoveType::FLAG ? "Flag " : "Show ") << move.position << "\n";

        if (move.type == MoveType::FLAG)
            board.flag(move.position);
        else
            board.reveal(move.position);

        progress = true;
    }

    // Ensure a loss is treated as no forward progress
    if (board.isLost())
        return false;
    return progress;
}

Solver::Solver(bool show_debug)
    : DEBUG_LOG_(show_debug) {}

void Solver::addRule(std::unique_ptr<Rule> rule) {
    rules_.push_back(std::move(rule));
}

bool Solver::solve(const BitGrid& mines, const Vector2i& initial_tile) {
    // Copy the board
    Board board(mines);

    // Make the initialization move
    board.reveal(initial_tile);

    // Attempt to solve the board
    bool progress = true;
    while (progress && !board.isLost()) {
        // Create the solver state
        SolverState state(board);

        // Process moves in order of addition until one makes progress
        std::vector<Move> moves;
        for (auto& rule : rules_) {
            rule->apply(state, moves);
            progress = applyMoves_(board, moves);

            if (progress)
                break;
        }
    }

    // Log final board
    if (DEBUG_LOG_)
        std::clog << "FINAL BOARD:\n" << board << "\n";

    // Validate solve
    return board.isCleared();
}
