/*
    SmileButton.cpp

    Implementation for the minesweeper smile button
*/

#include "Minesweeper/Objects/SmileButton.hpp"
#include <Core/Services.hpp>

void SmileButton::updateTexture_() {
    switch(state_) {
        case (SmileState::PRESSED):
            sprite_->setTexture("faces/playing_pressed.png");
            break;
        case (SmileState::THINKING):
            sprite_->setTexture("faces/thinking.png");
            break;
        case (SmileState::WIN):
            sprite_->setTexture("faces/win.png");
            break;
        case (SmileState::LOSE):
            sprite_->setTexture("faces/lose.png");
            break;
        default:
            sprite_->setTexture("faces/playing.png");
    }
}

void SmileButton::onInit() {

}

void SmileButton::onUpdate(double dt) {
    auto viewport = Services::renderer()->viewport();
    auto input = Services::input();

    if (input->isHeld(MouseButton::LEFT)) {
        auto world_pos = scene()->camera().screenToWorld(input->mousePosition(), viewport);
        if (collider_->contains(world_pos))
            setState(SmileState::PRESSED);
        else if (state_ == SmileState::PLAYING || state_ == SmileState::PRESSED)
            setState(SmileState::THINKING);
    }

    else if (state_ == SmileState::THINKING || state_ == SmileState::PRESSED)
        setState(SmileState::PLAYING);
}

SmileButton::SmileButton() 
    : sprite_(addComponent<SpriteComponent>("faces/playing.png")),
      collider_(addComponent<BoxCollider2D>(Vector2::zero(), sprite_->size())),
      state_(SmileState::PLAYING) {}

void SmileButton::setState(SmileState state) {
    state_ = state;
    updateTexture_();
}
