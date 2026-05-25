/*
    Tile.cpp

    Implementation for a minesweeper tile
*/

#include "Minesweeper/Objects/Tile.hpp"
#include <Types/DimVector.hpp>
#include <Core/Services.hpp>

namespace {
    std::filesystem::path textureName(const std::string& name) {
        return "tiles/" + name + ".png";
    }
}

size_t Tile::tileSize() {
    return TILE_SIZE_;
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

Tile::Tile() 
    : sprite_(addComponent<SpriteComponent>(textureName("hidden"))) {}

TileState Tile::state() const {
    return state_;
}

void Tile::setState(TileState state) {
    state_ = state;
    updateTexture_();
}

TileValue Tile::value() const {
    return value_;
}

void Tile::setValue(TileValue value) {
    value_ = value;
    updateTexture_();
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

void Tile::expose() {
    if (isMine() && !isRevealed())
        setState(TileState::GAME_SHOWN);
    else if (isFlagged() && !isMine())
        setState(TileState::FALSE_FLAGGED);
}

bool Tile::isMine() const {
    return value_ == TileValue::MINE;
}

bool Tile::isRevealed() const {
    return state_ == TileState::PLAYER_SHOWN
        || state_ == TileState::GAME_SHOWN;
}

bool Tile::isFlagged() const {
    return state_ == TileState::FLAGGED;
}

void Tile::flag() {
    if (state_ == TileState::HIDDEN)
        setState(TileState::FLAGGED);
}

void Tile::unflag() {
    if (state_ == TileState::FLAGGED)
        setState(TileState::HIDDEN);
}

void Tile::reveal() {
    if (state_ != TileState::HIDDEN) 
        return;
    
    setState(TileState::PLAYER_SHOWN);

    if (value_ == TileValue::ZERO)
        revealNeighbors();
}

void Tile::revealNeighbors() {
    for (auto& neighbor : neighbors_)
        neighbor->reveal();
}

int Tile::neighboringFlags() {
    int flags = 0;
    for (auto& neighbor : neighbors_) {
        if (neighbor->state() == TileState::FLAGGED)
            ++flags;
    }
    return flags;
}
