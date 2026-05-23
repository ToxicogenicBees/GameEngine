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
     */
    void drawTexture(std::shared_ptr<Texture> texture, Vector2 pos);

    /**
     * @brief Presents the rendered image to the window.
     */
    void present();

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