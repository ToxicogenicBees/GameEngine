/*
    RenderSystem.cpp

    Implementation of a render system, in charge of collecting, sorting, and calling a render for objects.
*/

#include "Rendering/RenderSystem.hpp"
#include "Components/Graphics/SpriteComponent.hpp"
#include "World/GameObject.hpp"
#include "World/Scene.hpp"

RenderSystem::RenderSystem()
    : Subsystem("RenderSystem")
{
    addDependency<Renderer>();
}

void RenderSystem::resolveDependencies(Macrosystem* system) {
    renderer_ = system->fetchSystem<Renderer>();
}

void RenderSystem::renderSprites_() {
    for (auto& sprite : sprites_) {
        renderer_->draw(
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
