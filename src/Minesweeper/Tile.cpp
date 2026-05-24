/*
    Tile.cpp

    Implementation for a minesweeper tile
*/

#include "Minesweeper/Tile.hpp"
#include <Core/Services.hpp>

namespace {
    std::filesystem::path textureName(const std::string& name) {
        return "tiles/" + name + ".png";
    }
}

void Tile::onInit() {
    updateTexture_();
}

void Tile::updateTexture_() {
    std::filesystem::path name;
    if (state_ == TileState::FLAGGED)
        name = textureName("flag");
    else if (state_ == TileState::HIDDEN)
        name = textureName("hidden");
    else if (value_ == TileValue::MINE)
        name = textureName("mine");
    else
        name = textureName(std::to_string((int)value_));

    auto texture = Services::assets()->loadTexture(name);
    sprite_->setTexture(texture);
}

Tile::Tile() 
    : sprite_(addComponent<SpriteComponent>()) {}

TileState Tile::state() const {
    return state_;
}

void Tile::setState(TileState state) {
    // Set the state
    state_ = state;

    // Update texture
    updateTexture_();
}

TileValue Tile::value() const {
    return value_;
}

void Tile::setValue(TileValue value) {
    value_ = value;
}

uint8_t Tile::mineCount() const {
    uint8_t count = 0;
    for (const auto neighbor : neighbors_) {
        if (neighbor->isMine())
            ++count;
    }

    return count;
}

void Tile::addNeighbor(Tile* neighbor) {
    neighbors_.push_back(neighbor);
}

bool Tile::isMine() const {
    return value_ == TileValue::MINE;
}

bool Tile::isRevealed() const {
    return state_ == TileState::REVEALED;
}

bool Tile::isFlagged() const {
    return state_ == TileState::FLAGGED;
}

void Tile::flag() {
    if (state_ == TileState::HIDDEN) {
        state_ = TileState::FLAGGED;
        updateTexture_();
    }
}

void Tile::unflag() {
    if (state_ == TileState::FLAGGED){
        state_ = TileState::HIDDEN;
        updateTexture_();
    }
}

void Tile::reveal() {
    if (state_ != TileState::HIDDEN) 
        return;
    
    state_ = TileState::REVEALED;
    updateTexture_();

    if (value_ == TileValue::ZERO) {
        for (auto& neighbor : neighbors_)
            neighbor->reveal();
    }
}
