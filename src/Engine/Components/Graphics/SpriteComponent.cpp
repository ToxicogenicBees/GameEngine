/*
    SpriteComponent.cpp

    Implementation for a component containing a 2D sprite
*/

#include "Components/Graphics/SpriteComponent.hpp"
#include "World/GameObject.hpp"
#include "Core/Services.hpp"

SpriteComponent::SpriteComponent(GameObject& owner, TextureHandle texture, Vector2i offset, Size size)
    : Component(owner),
      Sprite(texture, offset, size)
{
    Services::renderSystem()->registerSprite(this);
}

SpriteComponent::SpriteComponent(GameObject& owner, TextureHandle texture)
    : Component(owner),
      Sprite(texture)
{
    Services::renderSystem()->registerSprite(this);
}

SpriteComponent::SpriteComponent(GameObject& owner)
    : Component(owner),
      Sprite()
{
    Services::renderSystem()->registerSprite(this);
}

Vector2 SpriteComponent::anchor() const {
    return anchor_;
}

void SpriteComponent::setAnchor(Vector2 anchor) {
    anchor_ = anchor;
}

SpriteComponent::~SpriteComponent() {
    Services::renderSystem()->unregisterSprite(this);
}