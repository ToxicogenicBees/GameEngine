/*
    Engine.cpp

    Implementation for the game engine control class
*/

#include "Core/Engine.hpp"
#include "Core/Services.hpp"
#include "Events/EventTypes/MouseButtonEvent.hpp"
#include "Events/EventTypes/WindowCloseEvent.hpp"
#include "Events/EventTypes/MouseMotionEvent.hpp"
#include "Events/EventTypes/KeyEvent.hpp"
#include "Events/EngineEventDispatcher.hpp"
#include "Events/EngineEventQueue.hpp"
#include "Types/Size.hpp"
#include <SDL3/SDL.h>
#include <thread>

Engine::Engine(const std::string& name)
    : window_(name), renderer_(window_), assets_()
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
    // Calculate time difference
    auto now = Clock::now();
    auto microsec = std::chrono::duration_cast<std::chrono::microseconds>(now - prev_time_).count();
    double dt = 1e-6 * microsec;
    prev_time_ = now;

    // Start input state
    input_.startUpdate(dt);

    // Poll engine events
    processSDLEvents_();

    // Dispatch engine events
    EngineEventQueue::dispatch();

    // End input update
    input_.endUpdate(dt);

    // Update gameplay layer
    scene_manager_.update(dt);
    
    // Render
    renderer_.clear({0, 0, 0, 255});
    scene_manager_.render();
    renderer_.present();

    // Wait a moment
    // @TODO: Add frame limiting
    SDL_Delay(1);
}

void Engine::processSDLEvents_() {
    SDL_Event event;

    // Create and push events
    while (SDL_PollEvent(&event)) {
        // Mouse pressed
        if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN || event.type == SDL_EVENT_MOUSE_BUTTON_UP) {
            auto pressed = event.type == SDL_EVENT_MOUSE_BUTTON_DOWN;
            Vector2 pos = {event.button.x, event.button.y};
            if (event.button.button == SDL_BUTTON_LEFT)
                EngineEventQueue::push(std::make_unique<MouseButtonEvent>(MouseButton::LEFT, pressed, pos));
            else if (event.button.button == SDL_BUTTON_RIGHT)
                EngineEventQueue::push(std::make_unique<MouseButtonEvent>(MouseButton::RIGHT, pressed, pos));
            else if (event.button.button == SDL_BUTTON_MIDDLE)
                EngineEventQueue::push(std::make_unique<MouseButtonEvent>(MouseButton::MIDDLE, pressed, pos));
        }

        // Mouse moved
        if (event.type == SDL_EVENT_MOUSE_MOTION) {
            Vector2 pos = {event.motion.x, event.motion.y};
            EngineEventQueue::push(std::make_unique<MouseMotionEvent>(pos));
        }
        
        // Quit
        if (event.type == SDL_EVENT_QUIT)
            EngineEventQueue::push(std::make_unique<WindowCloseEvent>());
    }
}
