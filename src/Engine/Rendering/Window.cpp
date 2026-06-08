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

void Window::onInit() {
    window_ = SDL_CreateWindow(
        NAME_.c_str(),
        size_.width(),
        size_.height(),
        SDL_LOGICAL_PRESENTATION_LETTERBOX
    );

    SDL_SetWindowFullscreenMode(window_, nullptr);
}

void Window::onShutdown() {
    SDL_DestroyWindow(window_);
    window_ = nullptr;
}

Window::Window(const std::string& name)
    : Subsystem("Window"),
      NAME_(name),
      size_(0.8 * getMonitorSize())
{}

SDL_Window* Window::raw() const {
    return window_;
}

void Window::setFullscreen(bool enabled) {
    SDL_SetWindowFullscreen(window_, enabled);
}

bool Window::isFullscreen() {
    return (SDL_GetWindowFlags(window_) & SDL_WINDOW_FULLSCREEN);
}

void Window::setSize(const Size& size) {
    SDL_SetWindowSize(window_, static_cast<int>(size.width()), static_cast<int>(size.height()));
}

Size Window::size() const {
    int w, h;
    SDL_GetWindowSize(window_, &w, &h);

    return Size{static_cast<size_t>(w), static_cast<size_t>(h)};
}

const std::string& Window::name() const {
    return NAME_;
}
