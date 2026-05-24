/*
    Application.cpp

    Implementation for a game application
*/

#include "Core/Application.hpp"
#include <stdexcept>
#include <SDL3/SDL.h>
#include <string>

Application::Application(const std::string& name) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        throw std::runtime_error(
            std::string("Failed to initialize SDL3: ") + SDL_GetError()
        );
    }

    engine_ = std::make_unique<Engine>(name);
}

void Application::run() {
    init();

    engine_->run();

    shutdown();
}

Application::~Application() {
    SDL_Quit();
}
