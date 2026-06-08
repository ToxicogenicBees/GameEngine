/*
    SmileButton.cpp

    Implementation for the minesweeper smile button
*/

#include "Minesweeper/Game/Objects/SmileButton.hpp"
#include <Core/Services.hpp>

namespace {
    std::filesystem::path textureName(const std::string& name) {
        return "textures/faces/" + name + ".png";
    }
}

void SmileButton::updateTexture_() {
    std::filesystem::path name;
    switch(state_) {
        case (SmileState::PRESSED):
            name = textureName("playing_pressed");
            break;
        case (SmileState::THINKING):
            name = textureName("thinking");
            break;
        case (SmileState::WIN):
            name = textureName("win");
            break;
        case (SmileState::LOSE):
            name = textureName("lose");
            break;
        default:
            name = textureName("playing");
    }

    if (!name.empty()) {
        auto texture = Services::resources()->loadTexture(name);
        sprite_->setTexture(texture);
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

SmileButton::SmileButton(Scene& scene) 
    : GameObject(scene),
      sprite_(addComponent<SpriteComponent>()),
      collider_(addComponent<BoxCollider2D>()),
      state_(SmileState::PLAYING)
{
    auto texture = Services::resources()->loadTexture(textureName("playing"));
    sprite_->setTexture(texture);

    sprite_->setLayer(20);

    collider_->setCenter(Vector2::zero());
    collider_->setSize(Vector2{
        static_cast<double>(sprite_->size().width()),
        static_cast<double>(sprite_->size().height())
    });
}

void SmileButton::setState(SmileState state) {
    state_ = state;
    updateTexture_();
}
