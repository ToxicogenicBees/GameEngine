/*
    Engine.cpp

    Implementation for the game engine control class
*/

#include "Communication/EngineEventQueue.hpp"
#include "UserInput/InputSystem.hpp"
#include "Engine.hpp"
#include <SDL3/SDL.h>

bool Engine::running_ = false;

/**
 * @brief Run the engine
 */
void Engine::run() {
    init_();
    while (running_)
        tick_();
    shutdown_();
}

/**
 * @brief Initialize the engine
 */
void Engine::init_() {
    // Initialize rendering
    SDL_Init(SDL_INIT_VIDEO);

    // Start the engine
    running_ = true;
}

/**
 * @brief Shutdown the engine
 */
void Engine::shutdown_() {
    // Quit rendering
    SDL_Quit();
}

/**
 * @brief Tick the engine
 */
void Engine::tick_() {
    // Poll user input
    InputSystem::poll();

    // Dispatch engine events
    EngineEventQueue::dispatch();

    // Update gameplay layer
    // Game::update();

    // Update renderer

}
