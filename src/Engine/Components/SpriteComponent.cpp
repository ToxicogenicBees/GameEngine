/*
    SpriteComponent.cpp

    Implementation for a component containing a 2D sprite
*/

#include "Components/SpriteComponent.hpp"
#include "GameObject/GameObject.hpp"
#include "Rendering/Renderer.hpp"
#include "Rendering/Camera.hpp"
#include "Core/Services.hpp"

void SpriteComponent::onRender(Camera& camera) {
    if (texture_) {
        Services::renderer()->drawTexture(
            texture_,
            owner_->transform(),
            offset_,
            camera
        );
    } 
}

void SpriteComponent::setTexture(std::shared_ptr<Texture> texture) {
    texture_ = texture;
}

std::shared_ptr<Texture> SpriteComponent::texture() const {
    return texture_;
}

DimVector SpriteComponent::offset() const {
    return offset_;
}

void SpriteComponent::setOffset(const DimVector& offset) {
    offset_ = offset;
}

Size SpriteComponent::size() const {
    return (texture_ ? texture_->size() : Size{0, 0});
}

size_t SpriteComponent::width() const {
    return (texture_ ? texture_->width() : 0);
}

size_t SpriteComponent::height() const {
    return (texture_ ? texture_->height() : 0);
}
