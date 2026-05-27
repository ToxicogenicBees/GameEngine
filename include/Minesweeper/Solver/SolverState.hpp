/*
    SolverState.hpp

    Declaration of a class containing the current state of a minesweeper solver
*/

#include "Minesweeper/Core/BitGrid.hpp"
#include "Minesweeper/Core/Board.hpp"
#include <Types/Vector2.hpp>
#include <stdint.h>
#include <vector>

class SolverState {
private:
    const Board* board_;

    BitGrid revealed_;
    BitGrid flagged_;
    BitGrid unknown_;
    BitGrid frontier_;
    BitGrid constraints_;

    std::vector<uint8_t> revealed_numbers_;
    std::vector<uint8_t> adjacent_flags_;
    std::vector<uint8_t> adjacent_unknown_;

    std::vector<std::vector<int>> neighbors_;

public:
    /**
     * @brief Constructor.
     * 
     * @param board The current board.
     */
    SolverState(const Board& board);

    bool isUnknown(const Vector2i& tile) const;
    bool isFrontier(const Vector2i& tile) const;
    bool isRevealed(const Vector2i& tile) const;
    bool isFlagged(const Vector2i& tile) const;

    std::vector<Vector2i> revealedTiles() const;
    std::vector<Vector2i> flaggedTiles() const;
    std::vector<Vector2i> unknownTiles() const;
    std::vector<Vector2i> frontierTiles() const;
    std::vector<Vector2i> constraintTiles() const;

    BitGrid adjacentTo(const BitGrid& grid) const;

    uint8_t adjacentFlagCount(const Vector2i& tile) const;
    uint8_t adjacentUnknownCount(const Vector2i& tile) const;
    uint8_t revealedNumber(const Vector2i& tile) const;

    std::vector<Vector2i> neighbors(const Vector2i& tile) const;
};
