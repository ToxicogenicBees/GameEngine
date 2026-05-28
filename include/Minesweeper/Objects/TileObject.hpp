/*
    TileObject.hpp

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

class TileObject : public GameObject {
private:
    static constexpr size_t TILE_SIZE_ = 16;
    const Vector2i INDEX_;

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

    /**
     * @brief Custom update logic
     * 
     * @param dt Time since last update
     */
    void onUpdate(double dt) override;

public:
    /**
     * @brief Constructor
     */
    TileObject(const Vector2i& index);

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

    /**
     * @brief Gets the index of this tile.
     */
    Vector2i index() const;
};
