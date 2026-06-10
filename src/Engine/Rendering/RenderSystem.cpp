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
    addDependency<ResourceManager>();
    addDependency<Renderer>();
}

void RenderSystem::resolveDependencies(Macrosystem* system) {
    resource_manager_ = system->fetchSystem<ResourceManager>();
    renderer_ = system->fetchSystem<Renderer>();
}

void RenderSystem::renderSprites_() {
    // Render individual sprite
    auto render_sprite = [this](SpriteComponent* sprite) {
        // Fetch info
        auto transform = sprite->owner()->transform();
        auto camera = sprite->scene()->camera();
        auto anchor = sprite->anchor();
        auto offset = sprite->offset();
        auto size = sprite->size();

        // Calculate quad rectangle
        auto screen_pos = camera.worldToScreen(transform.position() - offset);
        auto w = size.width() * transform.scale().x;
        auto h = size.height() * transform.scale().y;
        Vector2 anchor_pixels{
            w * anchor.x,
            h * anchor.y
        };
        SDL_FRect dst {
            static_cast<float>(screen_pos.x - 0.5 * w + anchor_pixels.x),
            static_cast<float>(screen_pos.y - 0.5 * h + anchor_pixels.y),
            static_cast<float>(w * camera.zoom()),
            static_cast<float>(h * camera.zoom())
        };

        // Resolve texture
        auto texture_handle = sprite->texture();
        auto texture = resource_manager_->resolve(texture_handle);
        if (!texture)
            ENGINE_FATAL(RENDERER, "Failed to resolve texture");

        // Render texture
        Quad quad(dst, transform.rotation());
        renderer_->draw(quad, texture);
    };

    // Render all sprites
    for (auto& sprite : sprites_)
        render_sprite(sprite);
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

const RenderSystem::RenderStats& RenderSystem::stats() const {
    return stats_;
}
