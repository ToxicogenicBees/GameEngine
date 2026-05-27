/*
    RevealNeighbors.cpp

    Implementation for a rule that reveals neighboring tiles when applicable.
*/

#include "Minesweeper/Solver/Rules/RevealNeighbors.hpp"

void RevealNeighbors::apply(const SolverState& state, std::vector<Move>& out) const {
    for (auto tile : state.revealedTiles()) {
        // Get neighbors
        auto neighbors = state.neighbors(tile);

        // Count mines
        uint8_t mine_count = 0;
        for (auto neighbor : neighbors) {
            if (state.isFlagged(neighbor))
                ++mine_count;
        }

        // Reveal tiles if there's enough known mine tiles around
        auto neighbor_count = neighbors.size();
        if (state.revealedNumber(tile) == mine_count) {
            for (auto neighbor : neighbors) {
                if (state.isUnknown(neighbor))
                    out.push_back(Move{MoveType::REVEAL, neighbor});
            }
        }
    }
}
