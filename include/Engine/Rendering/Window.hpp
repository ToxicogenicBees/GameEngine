/*
    Window.hpp

    Declaration for a SDL3 window class wrapper
*/

#pragma once

#include "Platform/PlatformWindow.hpp"
#include "Core/System/Subsystem.hpp"
#include "Geometry/Size.hpp"
#include <SDL3/SDL.h>
#include <string>

class Window final : public PlatformWindow, public Subsystem {
private:
    SDL_Window* window_ = nullptr;
    Size size_;

protected:
    /**
     * @brief Custom resize logic.
     */
    void onResize(size_t width, size_t height) final;

    /**
     * @brief Custom state change logic.
     */
    void onStateChange(WindowState state) final;

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
     * @param title The title of the window to create.
     */
    Window(const std::string& title);

    /**
     * @brief Gets the raw SDL window pointer for this window.
     * 
     * @return The window pointer for this window.
     */
    SDL_Window* raw() const;
};
