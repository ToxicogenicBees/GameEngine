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
    Size size_;

public:
    /**
     * @brief Constructor
     * 
     * @param name The title of the window to create.
     */
    Window(const std::string& name);

    /**
     * @brief Gets the raw SDL window pointer for this window.
     * 
     * @return The window pointer for this window.
     */
    SDL_Window* raw() const;

    /**
     * @brief Sets the fullscreen state of the window.
     * 
     * @param enabled Whether fullscreen should be enabled or not.
     */
    void setFullscreen(bool enabled);

    /**
     * @brief Gets whether the screen is fullscreen or not.
     * 
     * @return True if the screen is fullscreen, false otherwise.
     */
    bool isFullscreen();

    /**
     * @brief Sets the size of the window.
     * 
     * @param width The desired width of the window.
     * @param height The desired sheight of the window.
     */
    void setSize(size_t width, size_t height);

    /**
     * @brief Sets the size of the window.
     * 
     * @param size The desired size of the window.
     */
    void setSize(const Size& size);

    /**
     * @brief Gets the size of the window.
     * 
     * @return The size of the window.
     */
    Size size() const;

    /**
     * @brief Gets the width of the window.
     * 
     * @return The width of the window.
     */
    size_t width() const;

    /**
     * @brief Gets the height of the window.
     * 
     * @return The height of the window.
     */
    size_t height() const;

    /**
     * @brief Destructor
     */
    ~Window();
};
