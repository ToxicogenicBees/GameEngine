/*
    Window.hpp

    Declaration for a SDL3 window class wrapper
*/

#pragma once

#include "Core/System/Subsystem.hpp"
#include "Resources/Textures/Texture.hpp"
#include "Graphics/Color4.hpp"
#include "Geometry/Size.hpp"
#include <SDL3/SDL.h>
#include <string>
#include <memory>

class Window final : public Subsystem {
private:
    const std::string NAME_;
    SDL_Window* window_ = nullptr;
    Size size_;

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
     * @brief Gets the name of the window.
     * 
     * @return The name of the window.
     */
    const std::string& name() const;
};
