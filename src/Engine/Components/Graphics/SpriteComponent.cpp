/*
    SpriteComponent.cpp

    Implementation for a component containing a 2D sprite
*/

#include "Components/Graphics/SpriteComponent.hpp"
#include "Rendering/RenderSystem.hpp"
#include "Rendering/Renderer.hpp"
#include "World/Camera.hpp"
#include "World/GameObject.hpp"
#include "Core/Services.hpp"
#include <iostream>

void SpriteComponent::onRender() {
    Services::renderer()->draw(
        sprite_,
        owner_->transform(),
        anchor_,
        owner_->scene()->camera()
    );
}

void SpriteComponent::onInit() {
    RenderSystem::registerObject(this);
}

SpriteComponent::SpriteComponent(const Sprite& sprite)
    : sprite_(sprite) {}

void SpriteComponent::setSprite(const Sprite& sprite) {
    sprite_ = sprite;
}

Sprite SpriteComponent::sprite() const {
    return sprite_;
}

Vector2 SpriteComponent::anchor() const {
    return anchor_;
}

void SpriteComponent::setAnchor(const Vector2& anchor) {
    anchor_ = anchor;
}

Size SpriteComponent::size() const {
    auto base = sprite_.size();
    return Size(
        (size_t)(base.width() * owner_->transform().scale().x),
        (size_t)(base.height() * owner_->transform().scale().y)
    );
}

SpriteComponent::~SpriteComponent() {
    RenderSystem::unregisterObject(this);
}
