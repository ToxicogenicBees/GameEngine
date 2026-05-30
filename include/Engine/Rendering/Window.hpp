/*
    Window.hpp

    Declaration for a SDL3 window class wrapper
*/

#pragma once

#include "Core/Interfaces/IService.hpp"
#include "Resources/Textures/Texture.hpp"
#include "Types/Color4.hpp"
#include "Types/Size.hpp"
#include <SDL3/SDL.h>
#include <string>
#include <memory>

class Window : public IService {
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
     * @brief Destructor
     */
    ~Window();
};
