/*
    SmileButton.cpp

    Implementation for the minesweeper smile button
*/

#include "Minesweeper/Game/Objects/SmileButton.hpp"
#include <Core/Services.hpp>

void SmileButton::updateTexture_() {
    std::filesystem::path name;
    switch(state_) {
        case (SmileState::PRESSED):
            name = "faces/playing_pressed.png";
            break;
        case (SmileState::THINKING):
            name = "faces/thinking.png";
            break;
        case (SmileState::WIN):
            name = "faces/win.png";
            break;
        case (SmileState::LOSE):
            name = "faces/lose.png";
            break;
        default:
            name = "faces/playing.png";
    }

    if (!name.empty()) {
        auto texture = Services::resources()->loadTexture(name);
        auto sprite = Sprite(texture);
        sprite_->setSprite(sprite);
    }
}

void SmileButton::onInit() {
    // Bind update events
    bindUpdate();
}

void SmileButton::onUpdate(double dt) {
    auto input = Services::input();

    if (input->isHeld(MouseButton::LEFT)) {
        auto world_pos = scene()->camera().screenToWorld(input->mousePosition());
        if (collider_->contains(world_pos))
            setState(SmileState::PRESSED);
        else if (state_ == SmileState::PLAYING || state_ == SmileState::PRESSED)
            setState(SmileState::THINKING);
    }

    else if (state_ == SmileState::THINKING || state_ == SmileState::PRESSED)
        setState(SmileState::PLAYING);
}

SmileButton::SmileButton() 
    : sprite_(addComponent<SpriteComponent>()),
      collider_(addComponent<BoxCollider2D>()),
      state_(SmileState::PLAYING)
{
    auto texture = Services::resources()->loadTexture("faces/playing.png");
    auto sprite = Sprite(texture);
    sprite_->setSprite(sprite);

    sprite_->setLayer(20);

    collider_->setCenter(Vector2::zero());
    collider_->setSize(Vector2{
        (double)sprite_->size().width(),
        (double)sprite_->size().height()
    });
}

void SmileButton::setState(SmileState state) {
    state_ = state;
    updateTexture_();
}
