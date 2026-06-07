/*
    SolverState.hpp

    Declaration of a class containing the current state of a minesweeper solver
*/

#include "Minesweeper/Core/BitGrid.hpp"
#include "Minesweeper/Core/Board.hpp"
#include <Math/Vector2.hpp>
#include <cstdint>
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

    /**
     * @brief Gets if the specific tile is unknown.
     * 
     * @param tile The index of the desired tile.
     * @return True if the tile is unknown, false otherwise.
     */
    bool isUnknown(const Vector2i& tile) const;

    /**
     * @brief Gets if the specific tile is on the frontier.
     * 
     * @param tile The index of the desired tile.
     * @return True if the tile is on the frontier, false otherwise.
     */
    bool isFrontier(const Vector2i& tile) const;

    /**
     * @brief Gets if the specific tile is revealed.
     * 
     * @param tile The index of the desired tile.
     * @return True if the tile is revealed, false otherwise.
     */
    bool isRevealed(const Vector2i& tile) const;

    /**
     * @brief Gets if the specific tile is flagged.
     * 
     * @param tile The index of the desired tile.
     * @return True if the tile is flagged, false otherwise.
     */
    bool isFlagged(const Vector2i& tile) const;

    /**
     * @brief Gets a vector of all revealed tile indices.
     * 
     * @return A vector of all revealed tile indices.
     */
    std::vector<Vector2i> revealedTiles() const;

    /**
     * @brief Gets a vector of all flagged tile indices.
     * 
     * @return A vector of all flagged tile indices.
     */
    std::vector<Vector2i> flaggedTiles() const;

    /**
     * @brief Gets a vector of all unknown tile indices.
     * 
     * @return A vector of all unknown tile indices.
     */
    std::vector<Vector2i> unknownTiles() const;

    /**
     * @brief Gets a vector of all frontier tile indices.
     * 
     * @return A vector of all frontier tile indices.
     */
    std::vector<Vector2i> frontierTiles() const;

    /**
     * @brief Gets a vector of all constraint tile indices.
     * 
     * @return A vector of all constraint tile indices.
     */
    std::vector<Vector2i> constraintTiles() const;


    /**
     * @brief Gets a bit grid of all tile adjacent to those in another grid.
     * 
     * @param grid The grid whose adjacents are being found.
     * @return The grid of all adjacent tiles to the provided grid.
     */
    BitGrid adjacentTo(const BitGrid& grid) const;

    /**
     * @brief Gets the number of flags adjacent to a specific tile.
     * 
     * @param tile The index of the desired tile.
     * @return The number of flags adjacent to the specified tile. 
     */
    uint8_t adjacentFlagCount(const Vector2i& tile) const;

    /**
     * @brief Gets the number of unknown tiles adjacent to a specific tile.
     * 
     * @param tile The index of the desired tile.
     * @return The number of unknown tiles adjacent to the specified tile. 
     */
    uint8_t adjacentUnknownCount(const Vector2i& tile) const;

    /**
     * @brief Gets the number revealed on a specified tile.
     *        Throws an error if this tile has not been revealed.
     * 
     * @param tile The index of the desired tile.
     * @return The number revealed on the specified tile. 
     */
    uint8_t revealedNumber(const Vector2i& tile) const;

    /**
     * @brief Gets the neighboring tile indices of the specified tile.
     * 
     * @param tile The index of the desired tile.
     * @return The neighboring tile indices of the specified tile.
     */
    std::vector<Vector2i> neighbors(const Vector2i& tile) const;
};
