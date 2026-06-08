/*
    Renderer.hpp

    Declaration of a rendering object
*/

#pragma once

#include "Core/System/Subsystem.hpp"
#include "Core/System/Macrosystem.hpp"
#include "Graphics/Sprites/Sprite.hpp"
#include "Rendering/Window.hpp"
#include "World/Camera.hpp"
#include "Math/Transform.hpp"
#include "Math/Vector2.hpp"
#include "Geometry/Size.hpp"
#include <SDL3/SDL.h>
#include <memory>

class Renderer final : public Subsystem {
private:
    SDL_Renderer* renderer_ = nullptr;
    Window* window_ = nullptr;
    Size logical_size_;

    SDL_GPUDevice* device_ = nullptr;
    SDL_GPUCommandBuffer* cmd_ = nullptr;
    SDL_GPUGraphicsPipeline* pipeline_ = nullptr;

protected:
    /**
     * @brief Initialization logic.
     */
    void onInit() final;

    /**
     * @brief Shutdown logic.
     */
    void onShutdown() final;

public:
    /**
     * @brief Constructor
     */
    Renderer();
    
    /**
     * @brief Depencency resolution logic.
     */
    void resolveDependencies(Macrosystem* system) final;

    /**
     * @brief Clears the screen to a set color.
     * 
     * @param color The color the screen should be cleared to.
     */
    void clear(Color4 color);

    /**
     * @brief Render a sprite.
     * 
     * @param sprite The sprite to be rendered.
     * @param transform The sprite's transform.
     * @param anchor The sprite's anchor.
     * @param camera The camera rendering this sprite.
     */
    void draw(
        const Sprite& sprite,
        const Transform& transform,
        const Vector2& anchor,
        const Camera& camera
    );

    /**
     * @brief Presents the rendered image to the window.
     */
    void present();

    /**
     * @brief Set the logical size of the renderer.
     * 
     * @param width The desired logical width of the renderer.
     * @param height The desired logical height of the renderer.
     */
    void setLogicalSize(size_t width, size_t height);

    /**
     * @brief Set the logical size of the renderer.
     * 
     * @param size The desired logical size of the renderer.
     */
    void setLogicalSize(const Size& size);

    /**
     * @brief Get the logical size of the renderer.
     * 
     * @return The logical size of the renderer.
     */
    Size logicalSize() const;

    /**
     * @brief Gets the viewport of the renderer.
     * 
     * @return The viewport of the renderer.
     */
    Viewport viewport() const;

    /**
     * @brief Gets the raw SDL renderer pointer.
     * 
     * @return The raw SDL renderer pointer.
     */
    SDL_Renderer* raw() const;
};
