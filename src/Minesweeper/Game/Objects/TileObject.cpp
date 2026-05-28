/*
    TileObject.cpp

    Implementation for a minesweeper tile
*/

#include "Minesweeper/Game/Objects/TileObject.hpp"
#include <Types/DimVector.hpp>
#include <Core/Services.hpp>
#include <optional>
#include <iostream>

namespace {
    std::filesystem::path textureName(const std::string& name) {
        return "tiles/" + name + ".png";
    }
}

size_t TileObject::tileSize() {
    return TILE_SIZE_;
}

void TileObject::onUpdate(double dt) {
    updateTexture_();
}

void TileObject::updateTexture_() {
    std::filesystem::path name;

    auto held = Services::input()->isHeld(MouseButton::LEFT);
    auto mouse_pos = Services::input()->mousePosition();
    std::optional<Vector2> world_pos;
    if (scene())
        world_pos = scene()->camera().screenToWorld(mouse_pos);

    if (world_pos.has_value() && held && collider_->contains(world_pos.value()) && !isRevealed() && !isFlagged())
        name = textureName("0");
    else if (board()->isLost()) {
        if (isMine() && !isRevealed() && !isFlagged())
            name = textureName("mine");
        if (isMine() && isRevealed())
            name = textureName("mine_red");
        if (!isMine() && isFlagged())
            name = textureName("mine_wrong");
    }
    else if (isFlagged())
        name = textureName("flag");
    else if (!isRevealed())
        name = textureName("hidden");
    else if (isMine())
        name = textureName("mine");
    else
        name = textureName(std::to_string((int)adjacentMineCount()));

    if (!name.empty()) {
        auto texture = Services::assets()->loadTexture(name);
        sprite_->setTexture(texture);
    }
}

TileObject::TileObject(Board* const board, const Vector2i& index)
    : TileWrapper(board, index),
      sprite_(addComponent<SpriteComponent>(textureName("hidden"))),
      collider_(addComponent<BoxCollider2D>(Vector2::zero(), Vector2{(double)sprite_->size().width(), (double)sprite_->size().height()}))
{}