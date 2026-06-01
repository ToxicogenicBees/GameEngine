/*
    SpriteComponent.cpp

    Implementation for a component containing a 2D sprite
*/

#include "Components/Rendering/SpriteComponent.hpp"
#include "Rendering/Renderer.hpp"
#include "World/Camera.hpp"
#include "World/GameObject.hpp"
#include "Core/Services.hpp"

void SpriteComponent::onRender(Camera& camera) {
    if (texture_) {
        Services::renderer()->drawTexture(
            texture_,
            owner_->transform(),
            anchor_,
            camera
        );
    } 
}

SpriteComponent::SpriteComponent(std::shared_ptr<Texture> texture)
    : texture_(texture) {}

void SpriteComponent::setTexture(std::shared_ptr<Texture> texture) {
    texture_ = texture;
}

std::shared_ptr<Texture> SpriteComponent::texture() const {
    return texture_;
}

Vector2 SpriteComponent::anchor() const {
    return anchor_;
}

void SpriteComponent::setAnchor(const Vector2& anchor) {
    anchor_ = anchor;
}

Size SpriteComponent::size() const {
    if (texture_) {
        auto base = texture_->size();
        return Size(
            (size_t)(base.width() * owner_->transform().scale().x),
            (size_t)(base.height() * owner_->transform().scale().y)
        );
    }

    return Size{0, 0};
}
