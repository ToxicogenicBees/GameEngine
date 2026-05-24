/*
    Renderer.hpp

    Declaration of a rendering object
*/

#pragma once

#include "Rendering/Window.hpp"
#include <SDL3/SDL.h>
#include <memory>

class Renderer {
private:
    SDL_Renderer* renderer_ = nullptr;
    SDL_Window* window_ = nullptr;

public:
    /**
     * @brief Constructor
     * 
     * @param window Reference to the window this renderer outputs to
     */
    Renderer(Window& window);

    /**
     * @brief Clears the screen to a set color.
     * 
     * @param color The color the screen should be cleared to.
     */
    void clear(Color4 color);

    /**
     * @brief Render a texture.
     * 
     * @param texture The texture to be rendered.
     * @param pos The texture's position.
     * @param zoom The texture's zoom.
     */
    void drawTexture(std::shared_ptr<Texture> texture, const Vector2& pos, double zoom);

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
    Size logicalSize(const Size& size);

    /**
     * @brief Gets the raw SDL renderer pointer.
     * 
     * @return The raw SDL renderer pointer.
     */
    SDL_Renderer* raw() const;

    /**
     * @brief Destructor
     */
    ~Renderer();
};