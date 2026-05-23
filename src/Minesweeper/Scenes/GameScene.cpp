/*
    GameScene.cpp

    Implementation for a minesweeper game scene
*/

#include "Minesweeper/Scenes/GameScene.hpp"
#include <Assets/AssetManager.hpp>
#include <Rendering/Renderer.hpp>
#include <Input/InputManager.hpp>
#include <algorithm>
#include <random>

std::shared_ptr<Texture> GameScene::resolveTileTexture_(const Tile& tile) {
    switch (tile.state()) {
        case TileState::FLAGGED:
            return flag_;

        case TileState::REVEALED: {
            if (tile.isMine())
                return mine_;
            return numbers_[(int)tile.value()];
        }

        default:
            return hidden_;
    }
}

void GameScene::onLeftClick_() {
    auto tile = board_.tileAt(context().input().mousePosition());
    if (tile)
        tile->reveal();
}

void GameScene::onRightClick_() {
    auto tile = board_.tileAt(context().input().mousePosition());
    if (tile)
        tile->isFlagged() ? tile->unflag() : tile->flag();
}

void GameScene::onInit() {
    // Load special tiles textures
    hidden_ = context().assets().loadTexture("tiles/hidden.png");
    flag_ = context().assets().loadTexture("tiles/flag.png");
    mine_ = context().assets().loadTexture("tiles/mine.png");

    // Load tile number textures
    for (int i = 0; i < 9; ++i)
        numbers_[i] = context().assets().loadTexture("tiles/" + std::to_string(i) + ".png");
    
    // Generate the board
    board_.generate(100, [this]() {
        return create<Tile>();
    });

    // Subscribe to mouse events
    subscribe<MouseButtonEvent>([this](const MouseButtonEvent& event) {
        if (event.button == MouseButton::LEFT)
            onLeftClick_();
        else if (event.button == MouseButton::RIGHT)
            onRightClick_();
    });
}

void GameScene::onUpdate(double dt) {
    
}

void GameScene::onRender() {

}

void GameScene::onUnload() {

}

GameScene::GameScene(EngineContext& context) 
    : Scene(context), board_({25, 25}) {}
