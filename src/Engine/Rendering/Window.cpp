/*
    Window.cpp

    Implementation for a SDL3 window class wrapper
*/

#include "Rendering/Window.hpp"

namespace {
    Size getMonitorSize() {
        SDL_DisplayID display = SDL_GetPrimaryDisplay();

        const SDL_DisplayMode* mode =
            SDL_GetCurrentDisplayMode(display);

        if (!mode)
            return {1280, 720};

        return {
            static_cast<size_t>(mode->w),
            static_cast<size_t>(mode->h)
        };
    }
}

void Window::onResize(size_t width, size_t height) {
    SDL_SetWindowSize(window_, static_cast<int>(width), static_cast<int>(height));
}

void Window::onStateChange(WindowState state) {
    // @TODO: Implement fullscreen/boarderless/windowed modes
}

void Window::onInit() {
    window_ = SDL_CreateWindow(
        title().c_str(),
        size().width(),
        size().height(),
        SDL_LOGICAL_PRESENTATION_LETTERBOX
    );

    SDL_SetWindowFullscreenMode(window_, nullptr);
}

void Window::onShutdown() {
    SDL_DestroyWindow(window_);
    window_ = nullptr;
}

Window::Window(const std::string& title)
    : PlatformWindow(title, 0.8 * getMonitorSize()),
      Subsystem("Window")
{}

SDL_Window* Window::raw() const {
    return window_;
}
