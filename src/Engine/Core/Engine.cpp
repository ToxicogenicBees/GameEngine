/*
    Engine.cpp

    Implementation for the game engine control class
*/

#include "Core/Engine.hpp"
#include "Events/EventTypes/MouseButtonEvent.hpp"
#include "Events/EventTypes/WindowCloseEvent.hpp"
#include "Events/EventTypes/MouseMotionEvent.hpp"
#include "Events/EventTypes/KeyEvent.hpp"
#include "Events/EngineEventDispatcher.hpp"
#include "Events/EngineEventQueue.hpp"
#include "Core/Services.hpp"
#include "Core/RunService.hpp"
#include "Rendering/RenderSystem.hpp"
#include "Utility/ScopedTimer.hpp"
#include "Logging/Logger.hpp"
#include "Geometry/Size.hpp"
#include <SDL3/SDL.h>
#include <string>

namespace {
    constexpr size_t PHYSICS_FPS = 60;

    template<typename Process>
    void timeProcess(const std::string& process_name, Process process) {
        ScopedTimer timer(process_name);
        process();
    }
}

Engine::Engine(const std::string& name)
    : window_(name),
      renderer_(window_),
      render_system_(renderer_),
      assets_(),
      resources_(assets_),
      run_service_(on_fixed_update_, on_update_)
{
    // Initialize services
    Services::setAssets(&assets_);
    Services::setResources(&resources_);
    Services::setInput(&input_);
    Services::setRenderer(&renderer_);
    Services::setScenes(&scene_manager_);
    Services::setWindow(&window_);
    Services::setRunService(&run_service_);
    Services::setRenderSystem(&render_system_);
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

void Engine::init() {
    // Initialize the logger
    Logger::init();

    // Start the engine
    ENGINE_INFO("Engine initialization");
    running_ = true;

    // Stop running if the game window closes
    window_close_ = EngineEventDispatcher::subscribe<WindowCloseEvent>([this](const WindowCloseEvent& event) {
        running_ = false;
    });

    // Reset the timer
    timer_.reset();
}

void Engine::shutdown() {
    // Stop the engine
    EngineEventDispatcher::unsubscribe(std::move(window_close_));
    ENGINE_INFO("Engine shutdown");

    // Shutdown the logger
    Logger::shutdown();
}

void Engine::tick() {
    // Start frame timer
    Timer frame_timer;

    // Calculate time difference
    double frame_dt = timer_.seconds();
    timer_.reset();

    // Update accumulator
    accumulator_ += frame_dt;

    // Input management
    input_.startUpdate();
    processSDLEvents_();
    EngineEventQueue::dispatch();
    input_.endUpdate();

    // Update gameplay layer
    const double PHYSICS_DT = 1.0 / PHYSICS_FPS;
    while (accumulator_ >= PHYSICS_DT) {
        on_fixed_update_.fire(PHYSICS_DT);
        accumulator_ -= PHYSICS_DT;
    }
    on_update_.fire(frame_dt);
    
    interpolation_alpha_ = accumulator_ / PHYSICS_DT;
    
    // Render
    renderer_.clear({0, 0, 0, 255});
    render_system_.render();
    renderer_.present();
    
    scene_manager_.flushScene();
    scene_manager_.processSceneChange();
}

bool Engine::isRunning() const {
    return running_;
}
