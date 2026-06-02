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
#include "Utility/ScopedTimer.hpp"
#include "Geometry/Size.hpp"
#include <SDL3/SDL.h>
#include <string>

namespace {
    constexpr double FRAME_RATE = 1.0 / 30.0;

    template<typename Process>
    void timeProcess(const std::string& process_name, Process process) {
        ScopedTimer timer(process_name);
        process();
    }
}

Engine::Engine(const std::string& name)
    : window_(name), renderer_(window_), assets_(), resources_(assets_)
{
    // Initialize services
    Services::setAssets(&assets_);
    Services::setResources(&resources_);
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
    window_close_ = EngineEventDispatcher::subscribe<WindowCloseEvent>([this](const WindowCloseEvent& event) {
        running_ = false;
    });

    // Reset the timer
    timer_.reset();
}

void Engine::shutdown_() {
    EngineEventDispatcher::unsubscribe(std::move(window_close_));
}

void Engine::tick_() {
    // Start frame timer
    Timer frame_timer;

    // Calculate time difference
    double dt = timer_.seconds();
    timer_.reset();

    timeProcess("Engine tick", [this, dt]() {
        // Input management
        timeProcess("Input fetching", [this, dt]() {
            input_.startUpdate(dt);
            processSDLEvents_();
            EngineEventQueue::dispatch();
            input_.endUpdate(dt);
        });

        // Update gameplay layer
        timeProcess("Update cycle", [this, dt]() {
            scene_manager_.update(dt);
        });
        
        // Render
        timeProcess("Render cycle", [this]() {
            renderer_.clear({0, 0, 0, 255});
            scene_manager_.render();
            renderer_.present();
        });
    });

    // Wait for the desired frame limit to pass
    while (frame_timer.seconds() < FRAME_RATE)
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
