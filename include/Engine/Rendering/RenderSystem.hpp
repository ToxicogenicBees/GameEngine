/*
    RenderSystem.hpp

    Declaration of a render system, in charge of collecting, sorting, and calling a render for objects.
*/

#pragma once

#include "Core/System/Subsystem.hpp"
#include "Components/Graphics/SpriteComponent.hpp"
#include "Rendering/Renderer.hpp"
#include <vector>

class RenderSystem : public Subsystem {
private:
    struct RenderStats {
        size_t sprites = 0;
        size_t batches = 0;
        size_t draw_calls = 0;
        size_t vertices = 0;
    };

    std::vector<SpriteComponent*> sprites_;
    RenderStats stats_;
    Renderer* renderer_;

    /**
     * @brief Batches and renders sprites.
     */
    void renderSprites_();

public:
    /**
     * @brief Constructor.
     */
    RenderSystem();

    /**
     * @brief Depencency resolution logic.
     */
    void resolveDependencies(Macrosystem* system) final;

    /**
     * @brief Registers a sprite to the render system.
     * 
     * @param sprite The sprite being registered.
     */
    void registerSprite(SpriteComponent* sprite);

    /**
     * @brief Unregisters a sprite from the render system.
     * 
     * @param sprite The sprite being removed.
     */
    void unregisterSprite(SpriteComponent* sprite);

    /**
     * @brief Renders the list of objects to the active renderer.
     */
    void render();

    /**
     * @brief Gets the render statistics of the system.
     * 
     * @return The render statistics of the system.
     */
    const RenderStats& stats() const;
};
