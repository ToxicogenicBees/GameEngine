/*
    GameScene.cpp

    Implementation for a minesweeper game scene
*/

#include "Minesweeper/Scenes/GameScene.hpp"
#include <Core/Services.hpp>
#include <algorithm>
#include <random>

namespace {
    double WINDOW_SCALE = 2.0;
}

void GameScene::generate_(const Size& size, size_t mine_count) {
    // Update window
    auto render_size = Tile::tileSize() * size;
    Services::window()->setFullscreen(false);
    Services::window()->setSize(WINDOW_SCALE * render_size);
    Services::renderer()->setLogicalSize(render_size);
    camera().transform().position = Services::renderer()->viewport().center();

    // Generate the board
    auto creator = [this]() { return create<Tile>(); };
    auto destroyer = [this](Tile* tile) { destroy(tile); };
    board_->generate(size, mine_count, creator, destroyer);
}

void GameScene::onLeftClick_(const Vector2i& mouse_pos) {
    auto world_pos = camera().screenToWorld(mouse_pos, Services::renderer()->viewport());
    auto tile = board_->tileAt(world_pos / WINDOW_SCALE);

    if (!tile)
        return;
    
    // Reveal hidden tile
    if (!tile->isRevealed()) {
        tile->reveal();

        if (tile->isMine())
            generate_({25, 25}, 100);
    }

    // Reveal neighbors if total flags == value
    else if(tile->isRevealed() && (tile->neighboringFlags() == (int)tile->value()))
        tile->revealNeighbors();
    
}

void GameScene::onRightClick_(const Vector2i& mouse_pos) {
    auto world_pos = camera().screenToWorld(mouse_pos, Services::renderer()->viewport());
    auto tile = board_->tileAt(world_pos / WINDOW_SCALE);
    if (tile)
        tile->isFlagged() ? tile->unflag() : tile->flag();
}

void GameScene::onInit() {
    // Subscribe to mouse events
    subscribe<MouseButtonEvent>([this](const MouseButtonEvent& event) {
        if (event.button == MouseButton::LEFT)
            onLeftClick_(event.position);
        else if (event.button == MouseButton::RIGHT)
            onRightClick_(event.position);
    });

    // Generate a board
    board_ = create<RandomBoard>();
    //generate_({25, 25}, 100);
}

void GameScene::onUpdate(double dt) {

}
