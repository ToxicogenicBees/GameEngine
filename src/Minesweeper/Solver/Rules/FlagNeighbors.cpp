/*
    FlagNeighbors.cpp

    Implementation for a rule that flags neighboring tiles when applicable.
*/

#include "Minesweeper/Solver/Rules/FlagNeighbors.hpp"

void FlagNeighbors::apply(const SolverState& state, std::vector<Move>& out) const {
    for (auto tile : state.revealedTiles()) {
        // Get neighbors
        auto neighbors = state.neighbors(tile);

        // Count safe tiles
        uint8_t safe_tiles = 0;
        for (auto neighbor : neighbors) {
            if (state.isRevealed(neighbor))
                ++safe_tiles;
        }
        
        // Flag mines if there's enough known safe tiles around
        auto neighbor_count = neighbors.size();
        if (state.revealedNumber(tile) == neighbor_count - safe_tiles) {
            for (auto neighbor : neighbors) {
                if (state.isUnknown(neighbor))
                    out.push_back(Move{MoveType::FLAG, neighbor});
            }
        }
    }
}
