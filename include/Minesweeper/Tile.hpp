/*
    Tile.hpp

    Declaration for a minesweeper tile
*/

#pragma once

#include <Game/GameObjects/Sprite.hpp>
#include <memory>
#include <stdint.h>
#include <vector>

enum class TileValue {
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    MINE
};

enum class TileState {
    HIDDEN,
    REVEALED,
    FLAGGED,
};

class Tile : public Sprite {
private:
    std::vector<Tile*> neighbors_;
    TileState state_ = TileState::HIDDEN;
    TileValue value_ = TileValue::ZERO;

public:
    /**
     * @brief Constructor
     */
    Tile() = default;

    /**
     * @brief Gets the state of this tile.
     * 
     * @return The state of this tile.
     */
    TileState state() const;

    /**
     * @brief Sets the state of this tile.
     * 
     * @param state The state to set.
     */
    void setState(TileState state);

    /**
     * @brief Gets the value for this tile.
     * 
     * @return The value of this tile.
     */
    TileValue value() const;

    /**
     * @brief Sets the value of this tile.
     * 
     * @param value The value to set.
     */
    void setValue(TileValue value);

    /**
     * @brief Gets the count of neighboring mines for this tile.
     * 
     * @return The number of neighboring mines around this tile.
     */
    uint8_t mineCount() const;

    /**
     * @brief Adds a neighboring tile to this tile's list of neighbors.
     * 
     * @param neighbor A pointer to the neighboring tile to be added.
     */
    void addNeighbor(Tile* neighbor);

    /*
    * @brief Checks if this tile is a mine.
    * 
    * @return True if this tile is a mine, false otherwise.
    */
    bool isMine() const;

    /**
     * @brief Checks if this tile is revealed.
     * 
     * @return True if this tile is revealed, false otherwise.
     */
    bool isRevealed() const;

    /**
     * @brief Checks if this tile is flagged.
     * 
     * @return True if this tile is flagged, false otherwise.
     */
    bool isFlagged() const;

    /**
     * @brief Flags this tile.
     */
    void flag();

    /**
     * @brief Unflags this tile.
     */
    void unflag();
};
