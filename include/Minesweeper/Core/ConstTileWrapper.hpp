/*
    ConstTileWrapper.hpp

    Declaration of a wrapper class that wraps a minesweeper board's operations around a specific index.
*/

#pragma once

#include "Minesweeper/Core/Board.hpp"
#include <Math/Vector2.hpp>

class ConstTileWrapper {
private:
    const Vector2i INDEX_;
    const Board* const board_;

public:
    /**
     * @brief Constructor.
     * 
     * @param board A pointer to this tile's board.
     * @param index This tile's index.
     */
    ConstTileWrapper(const Board* const board, const Vector2i& index);

    /**
     * @brief Gets the neighboring tile indices of this tile.
     * 
     * @return A vector of neighboring tiles.
     */
    std::vector<ConstTileWrapper> neighbors() const;

    /**
     * @brief Gets the number of mines around this tile.
     */
    uint8_t adjacentMineCount() const;

    /**
     * @brief Gets the number of flags around this tile.
     * 
     * @return The number of flags around this tile.
     */
    uint8_t adjacentFlagCount() const;

    /**
     * @brief Gets the tile number shown on a revealed tile.
     *        Throws an error if the tile is not revealed
     * 
     * @return The number on the revealed tile
     */
    uint8_t revealedNumber() const;

    /**
     * @brief Gets if the desired tile is a mine.
     * 
     * @return True if the tile is a mine, false otherwise.
     */
    bool isMine() const;

    /**
     * @brief Gets if the desired tile is a flag.
     * 
     * @return True if the tile is a flag, false otherwise.
     */
    bool isFlagged() const;

    /**
     * @brief Gets if the desired tile is false flagged.
     * 
     * @return True if the tile is false flagged, false otherwise.
     */
    bool isFalseFlagged() const;

    /**
     * @brief Gets if the desired tile is revealed.
     * 
     * @return True if the tile is revealed, false otherwise.
     */
    bool isRevealed() const;

    /**
     * @brief Gets the tile's index.
     * 
     * @return The tile's index.
     */
    Vector2i index() const;

    /**
     * @brief Gets the pointer to this tile's board.
     * 
     * @return The pointer to this tile's board.
     */
    const Board* const board() const;
};
