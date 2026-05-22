/*
    Window.hpp

    Declaration for a SDL3 window class wrapper
*/

#pragma once

#include <SDL3/SDL.h>
#include "Rendering/Texture.hpp"
#include "Types/Color4.hpp"
#include "Types/Size.hpp"
#include <string>
#include <memory>

class Window {
private:
    SDL_Renderer* renderer_ = nullptr;
    SDL_Window* window_ = nullptr;

public:
    /**
     * @brief Constructor
     * 
     * @param name The title of the window to create.
     * @param size The size of the window to create.
     */
    Window(const std::string& name, const Size& size);

    /**
     * @brief Clears the screen with the specified color.
     * 
     * @param color The color to clear the screen with.
     */
    void clear(const Color4& color);

    /**
     * @brief Draws a game object to the screen.
     */
    void drawTexture(std::shared_ptr<Texture> texture, const Vector2& position);

    /**
     * @brief Renders the window.
     */
    void render();

    /**
     * @brief Gets the raw SDL renderer pointer for this window.
     * 
     * @return The renderer pointer for this window
     */
    SDL_Renderer* renderer() const;

    /**
     * @brief Gets the raw SDL window pointer for this window.
     * 
     * @return The window pointer for this window
     */
    SDL_Window* window() const;

    /**
     * @brief Destructor
     */
    ~Window();
};
