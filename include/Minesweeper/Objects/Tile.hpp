/*
    Tile.hpp

    Declaration for a minesweeper tile
*/

#pragma once

#include <GameObject/GameObject.hpp>
#include <Components/SpriteComponent.hpp>
#include <Components/BoxCollider2D.hpp>
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
    PLAYER_SHOWN,
    GAME_SHOWN,
    FLAGGED,
    FALSE_FLAGGED,
};

class Tile : public GameObject {
private:
    static constexpr size_t TILE_SIZE_ = 16;

    std::vector<Tile*> neighbors_;
    TileState state_ = TileState::HIDDEN;
    TileValue value_ = TileValue::ZERO;

    SpriteComponent* sprite_;
    BoxCollider2D* collider_;

    /**
     * @brief Sets the appropriate tile texture based on it's state
     */
    void updateTexture_();

    /**
     * @brief Custom intialization logic
     */
    void onInit() override;

public:
    /**
     * @brief Constructor
     */
    Tile();

    /**
     * @brief Gets the size of each tile.
     * 
     * @return The size of each tile.
     */
    static size_t tileSize();

    /**
     * @brief Sets the state of this tile.
     * 
     * @param state The state to set.
     */
    void setState(TileState state);

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

    /**
     * @brief Exposes the tile's true state, based on player's actions.
     */
    void expose();

    /**
     * @brief Reveals this tile.
     */
    void reveal();

    /**
     * @brief Reveals this tile's neighbors.
     */
    void revealNeighbors();

    /**
     * @brief Flags this tile.
     */
    void flag();

    /**
     * @brief Unflags this tile.
     */
    void unflag();

    /**
     * @brief Gets the number of flags surrounding this tile.
     * 
     * @return The number of flags surrounding this tile.
     */
    int neighboringFlags();

    /**
     * @brief Gets the state of this tile.
     * 
     * @return The state of this tile.
     */
    TileState state() const;

    /**
     * @brief Gets the value for this tile.
     * 
     * @return The value of this tile.
     */
    TileValue value() const;

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
};
