/*
    TileWrapperObject.hpp

    Declaration for a minesweeper tile
*/

#pragma once

#include <Core/GameObject.hpp>
#include <Components/SpriteComponent.hpp>
#include <Components/BoxCollider2D.hpp>
#include "Minesweeper/Core/TileWrapper.hpp"
#include "Minesweeper/Core/Board.hpp"
#include <memory>
#include <stdint.h>
#include <vector>

class TileObject : public GameObject, public TileWrapper {
private:
    static constexpr size_t TILE_SIZE_ = 16;

    SpriteComponent* sprite_;
    BoxCollider2D* collider_;

    /**
     * @brief Sets the appropriate tile texture based on it's state
     */
    void updateTexture_();

    /**
     * @brief Custom update logic
     * 
     * @param dt Time since last update
     */
    void onUpdate(double dt) override;

public:
    /**
     * @brief Constructor.
     * 
     * @param board A pointer to a minesweeper board.
     * @param index The index of this tile.
     */
    TileObject(Board* const board, const Vector2i& index);

    /**
     * @brief Gets the size of each tile.
     * 
     * @return The size of each tile.
     */
    static size_t tileSize();
};
