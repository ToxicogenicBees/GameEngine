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
            (size_t)mode->w,
            (size_t)mode->h
        };
    }
}

Window::Window(const std::string& name)
    : SIZE_(getMonitorSize())
{
    window_ = SDL_CreateWindow(
        name.c_str(),
        0.8 * SIZE_.width,
        0.8 * SIZE_.height,
        SDL_LOGICAL_PRESENTATION_LETTERBOX
    );

    SDL_SetWindowFullscreenMode(window_, nullptr);
}

SDL_Window* Window::raw() const {
    return window_;
}

Size Window::size() const {
    return SIZE_;
}

size_t Window::width() const {
    return SIZE_.width;
}

size_t Window::height() const {
    return SIZE_.height;
}

Window::~Window() {
    SDL_DestroyWindow(window_);
    window_ = nullptr;
}
