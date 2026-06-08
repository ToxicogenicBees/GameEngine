/*
    TileObject.cpp

    Implementation for a minesweeper tile
*/

#include "Minesweeper/Game/Objects/TileObject.hpp"
#include <Resources/Types/Texture.hpp>
#include <Core/Services.hpp>
#include <optional>

namespace {
    std::filesystem::path textureName(const std::string& name) {
        return "textures/tiles/" + name + ".png";
    }
}

size_t TileObject::tileSize() {
    return TILE_SIZE_;
}

void TileObject::onUpdate(double dt) {
    updateTexture_();
}

void TileObject::onInit() {
    // Bind update events
    bindUpdate();
}

void TileObject::updateTexture_() {
    std::filesystem::path name;

    auto held = Services::input()->isHeld(MouseButton::LEFT);
    auto mouse_pos = Services::input()->mousePosition();
    std::optional<Vector2> world_pos;
    if (scene())
        world_pos = scene()->camera().screenToWorld(mouse_pos);

    
    if (board()->isLost()) {
        if (isMine() && !isRevealed() && !isFlagged())
            name = textureName("mine");
        if (isMine() && isRevealed())
            name = textureName("mine_red");
        if (!isMine() && isFlagged())
            name = textureName("mine_wrong");
    }
    else if (world_pos.has_value() && held && collider_->contains(world_pos.value()) && !isRevealed() && !isFlagged())
        name = textureName("0");
    else if (isFlagged())
        name = textureName("flag");
    else if (!isRevealed())
        name = textureName("hidden");
    else if (isMine())
        name = textureName("mine");
    else
        name = textureName(std::to_string(static_cast<int>(adjacentMineCount())));

    if (!name.empty()) {
        auto texture = Services::resources()->load<Texture>(name);
        sprite_->setTexture(texture);
    }
}

TileObject::TileObject(Scene& scene, Board* const board, const Vector2i& index)
    : GameObject(scene),
      TileWrapper(board, index),
      sprite_(addComponent<SpriteComponent>()),
      collider_(addComponent<BoxCollider2D>())
{
    auto texture = Services::resources()->load<Texture>(textureName("hidden"));
    sprite_->setTexture(texture);

    sprite_->setLayer(10);

    collider_->setCenter(Vector2::zero());
    collider_->setSize(Vector2{
        static_cast<double>(sprite_->size().width()),
        static_cast<double>(sprite_->size().height())
    });
}