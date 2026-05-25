/*
    SmileButton.cpp

    Implementation for the minesweeper smile button
*/

#include "Minesweeper/Objects/SmileButton.hpp"
#include <Core/Services.hpp>
#include <iostream>

void SmileButton::updateTexture_() {

}

void SmileButton::onInit() {

}

void SmileButton::onUpdate(double dt) {
    std::clog << Services::input()->isHeld(MouseButton::LEFT) << " " << (int)state_ << "\n";
    if (Services::input()->isHeld(MouseButton::LEFT)) {
        if (state_ == SmileState::PLAYING) {
            setState(SmileState::THINKING);
            sprite_->setTexture("faces/thinking.png");
        }
    }

    else if (dirty_) {
        if (state_ == SmileState::THINKING) {
            setState(SmileState::PLAYING);
            sprite_->setTexture("faces/playing.png");
        }

        else if (state_ == SmileState::WIN)
            sprite_->setTexture("faces/win.png");

        else
            sprite_->setTexture("faces/lose.png");

        dirty_ = false;
    }
}

SmileButton::SmileButton() 
    : sprite_(addComponent<SpriteComponent>("faces/playing.png")),
      state_(SmileState::PLAYING) {}

void SmileButton::setState(SmileState state) {
    state_ = state;
    dirty_ = true;
}
