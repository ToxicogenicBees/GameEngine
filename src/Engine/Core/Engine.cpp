/*
    Engine.cpp

    Implementation for the game engine control class
*/

#include "Core/Engine.hpp"
#include "Core/Services.hpp"
#include "Events/EventTypes/WindowCloseEvent.hpp"
#include "Events/EngineEventDispatcher.hpp"
#include "Events/EngineEventQueue.hpp"
#include "Types/Size.hpp"
#include <SDL3/SDL.h>

Engine::Engine(const std::string& name)
    : window_(name), renderer_(window_), assets_(renderer_)
{
    // Initialize services
    Services::setAssets(&assets_);
    Services::setInput(&input_);
    Services::setRenderer(&renderer_);
    Services::setScenes(&scene_manager_);
    Services::setWindow(&window_);
}

void Engine::run() {
    init_();

    while (running_) {
        tick_();
    }
    
    shutdown_();
}

void Engine::init_() {
    // Start the engine
    running_ = true;

    // Stop running if the game window closes
    EngineEventDispatcher::subscribe<WindowCloseEvent>([this](const WindowCloseEvent& event) {
        running_ = false;
    });
}

void Engine::shutdown_() {

}

void Engine::tick_() {
    // Poll user input
    input_.poll();

    // Dispatch engine events
    EngineEventQueue::dispatch();

    // Calculate time difference
    auto now = Clock::now();
    auto microsec = std::chrono::duration_cast<std::chrono::microseconds>(now - prev_time_).count();
    double dt = 1e-6 * microsec;
    prev_time_ = now;

    // Update gameplay layer
    scene_manager_.update(dt);
    scene_manager_.render();

    // Render
    renderer_.present();
}
