/*
    TileObject.cpp

    Implementation for a minesweeper tile
*/

#include "Minesweeper/Objects/TileObject.hpp"
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

void TileObject::onInit() {
    updateTexture_();
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
    else if (state_ == TileState::FLAGGED)
        name = textureName("flag");
    else if (state_ == TileState::HIDDEN)
        name = textureName("hidden");
    else if (value_ == TileValue::MINE && state_ == TileState::PLAYER_SHOWN)
        name = textureName("mine_red");
    else if (value_ == TileValue::MINE && state_ == TileState::GAME_SHOWN)
        name = textureName("mine");
    else if (state_ == TileState::FALSE_FLAGGED)
        name = textureName("mine_wrong");
    else
        name = textureName(std::to_string((int)value_));

    auto texture = Services::assets()->loadTexture(name);
    sprite_->setTexture(texture);
}

TileObject::TileObject() 
    : sprite_(addComponent<SpriteComponent>(textureName("hidden"))),
      collider_(addComponent<BoxCollider2D>(Vector2::zero(), Vector2{(double)sprite_->size().width(), (double)sprite_->size().height()})) {}

TileState TileObject::state() const {
    return state_;
}

void TileObject::setState(TileState state) {
    state_ = state;
    updateTexture_();
}

TileValue TileObject::value() const {
    return value_;
}

void TileObject::setValue(TileValue value) {
    value_ = value;
    updateTexture_();
}

uint8_t TileObject::mineCount() const {
    uint8_t count = 0;
    for (const auto neighbor : neighbors_) {
        if (neighbor->isMine())
            ++count;
    }

    return count;
}

void TileObject::addNeighbor(TileObject* neighbor) {
    neighbors_.push_back(neighbor);
}

void TileObject::expose() {
    if (isMine() && !isFlagged() && !isRevealed())
        setState(TileState::GAME_SHOWN);
    else if (!isMine() && isFlagged())
        setState(TileState::FALSE_FLAGGED);
}

bool TileObject::isMine() const {
    return value_ == TileValue::MINE;
}

bool TileObject::isRevealed() const {
    return state_ == TileState::PLAYER_SHOWN
        || state_ == TileState::GAME_SHOWN;
}

bool TileObject::isFlagged() const {
    return state_ == TileState::FLAGGED;
}

void TileObject::flag() {
    if (state_ == TileState::HIDDEN)
        setState(TileState::FLAGGED);
}

void TileObject::unflag() {
    if (state_ == TileState::FLAGGED)
        setState(TileState::HIDDEN);
}

void TileObject::reveal() {
    if (state_ != TileState::HIDDEN) 
        return;
    
    setState(TileState::PLAYER_SHOWN);

    if (value_ == TileValue::ZERO)
        revealNeighbors();
}

void TileObject::revealNeighbors() {
    for (auto& neighbor : neighbors_)
        neighbor->reveal();
}

int TileObject::neighboringFlags() {
    int flags = 0;
    for (auto& neighbor : neighbors_) {
        if (neighbor->state() == TileState::FLAGGED)
            ++flags;
    }
    return flags;
}
