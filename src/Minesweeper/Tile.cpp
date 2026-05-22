/*
    Tile.cpp

    Implementation for a minesweeper tile
*/

#include "Assets/AssetManager.hpp"
#include "Minesweeper/Tile.hpp"

/**
 * @brief Gets the state of this tile.
 * 
 * @return The state of this tile.
 */
TileState Tile::state() const {
    return state_;
}

/**
 * @brief Sets the state of this tile.
 * 
 * @param state The state to set.
 */
void Tile::setState(TileState state) {
    state_ = state;
}

/**
 * @brief Gets the value for this tile.
 * 
 * @return The value of this tile.
 */
TileValue Tile::value() const {
    return value_;
}

/**
 * @brief Sets the value of this tile.
 * 
 * @param value The value to set.
 */
void Tile::setValue(TileValue value) {
    value_ = value;
}

/**
 * @brief Gets the count of neighboring mines for this tile.
 * 
 * @return The number of neighboring mines around this tile.
 */
uint8_t Tile::mineCount() const {
    uint8_t count = 0;
    for (const auto neighbor : neighbors_) {
        if (neighbor->isMine()) {
            ++count;
        }
    }

    return count;
}

/**
 * @brief Adds a neighboring tile to this tile's list of neighbors.
 * 
 * @param neighbor A pointer to the neighboring tile to be added.
 */
void Tile::addNeighbor(Tile* neighbor) {
    neighbors_.push_back(neighbor);
}

/*
* @brief Checks if this tile is a mine.
* 
* @return True if this tile is a mine, false otherwise.
*/
bool Tile::isMine() const {
    return value_ == TileValue::MINE;
}

/**
 * @brief Checks if this tile is revealed.
 * 
 * @return True if this tile is revealed, false otherwise.
 */
bool Tile::isRevealed() const {
    return state_ == TileState::REVEALED;
}

/**
 * @brief Checks if this tile is flagged.
 * 
 * @return True if this tile is flagged, false otherwise.
 */
bool Tile::isFlagged() const {
    return state_ == TileState::FLAGGED;
}

/**
 * @brief Flags this tile.
 */
void Tile::flag() {
    state_ = TileState::FLAGGED;
}

/**
 * @brief Unflags this tile.
 */
void Tile::unflag() {
    state_ = TileState::HIDDEN;
}
