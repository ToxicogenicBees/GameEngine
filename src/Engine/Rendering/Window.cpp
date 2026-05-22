/*
    Window.cpp

    Implementation for a SDL3 window class wrapper
*/

#include "Rendering/Window.hpp"

/**
 * @brief Constructor
 * 
 * @param name The title of the window to create.
 * @param size The size of the window to create.
 */
Window::Window(const std::string& name, const Size& size) {
    window_ = SDL_CreateWindow(
        name.c_str(),
        size.width,
        size.height,
        0
    );

    renderer_ = SDL_CreateRenderer(
        window_,
        nullptr
    );
}

/**
 * @brief Clears the screen with the specified color.
 * 
 * @param color The color to clear the screen with.
 */
void Window::clear(const Color4& color) {
    SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer_);
}

/**
 * @brief Draws a game object to the screen.
 */
void Window::drawTexture(std::shared_ptr<Texture> texture, const Vector2& position) {
    SDL_FRect dst {
        (float)position.x,
        (float)position.y,
        (float)texture->width(),
        (float)texture->height()
    };

    SDL_RenderTexture(
        renderer_,
        texture->raw(),
        nullptr,
        &dst
    );
}

/**
 * @brief Renders the window.
 */
void Window::render() {
    SDL_RenderPresent(renderer_);
}

/**
 * @brief Gets the raw SDL renderer pointer for this window.
 * 
 * @return The renderer pointer for this window
 */
SDL_Renderer* Window::renderer() const {
    return renderer_;
}

/**
 * @brief Gets the raw SDL window pointer for this window.
 * 
 * @return The window pointer for this window
 */
SDL_Window* Window::window() const {
    return window_;
}

/**
 * @brief Destructor
 */
Window::~Window() {
    SDL_DestroyWindow(window_);
    window_ = nullptr;

    SDL_DestroyRenderer(renderer_);
    renderer_ = nullptr;
}
