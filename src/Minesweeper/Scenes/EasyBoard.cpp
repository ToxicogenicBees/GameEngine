/*
    EasyBoard.cpp

    Implementation for a minesweeper game scene
*/

#include "Minesweeper/Scenes/EasyBoard.hpp"
#include <Core/Services.hpp>
#include <algorithm>
#include <random>

namespace {
    double WINDOW_SCALE = 2.0;

    // SMILE: 128, 16
}

void EasyBoard::onLeftClick_(const Vector2i& mouse_pos) {

}

void EasyBoard::onRightClick_(const Vector2i& mouse_pos) {

}

EasyBoard::EasyBoard()
    : board_(create<RandomBoard>()), smile_(create<SmileButton>())
{
    smile_->transform().position = {2, -131.5};
}

void EasyBoard::onInit() {
    // Set window size
    auto board_size = board_->getComponent<SpriteComponent>()->size();
    Services::renderer()->setLogicalSize(board_size);
    Services::window()->setSize(board_size);
}

void EasyBoard::onUpdate(double dt) {
    auto mouse_pos = Services::input()->mousePosition();
    if (Services::input()->wasPressed(MouseButton::LEFT))
        onLeftClick_(mouse_pos);
    else if (Services::input()->wasPressed(MouseButton::RIGHT))
        onRightClick_(mouse_pos);
}
