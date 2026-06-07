/*
    RenderSystem.cpp

    Implementation of a render system, in charge of collecting, sorting, and calling a render for objects.
*/

#include "Rendering/RenderSystem.hpp"
#include "Components/Graphics/SpriteComponent.hpp"
#include "Core/Services.hpp"
#include <algorithm>

RenderSystem::RenderSystem(Renderer& renderer)
    : renderer_(renderer) {}

void RenderSystem::renderSprites_() {
    for (auto& sprite : sprites_) {
        Services::renderer()->draw(
            *sprite,
            sprite->owner()->transform(),
            sprite->anchor(),
            sprite->scene()->camera()
        );
    }
}

void RenderSystem::registerSprite(SpriteComponent* sprite) {
    sprites_.push_back(sprite);
}

void RenderSystem::unregisterSprite(SpriteComponent* sprite) {
    std::erase_if(sprites_, [this, sprite](auto& spr) {
        return spr == sprite;
    });
}

void RenderSystem::render() {
    renderSprites_();
}
