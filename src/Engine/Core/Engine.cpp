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
#include "Resources/ResourceManager.hpp"
#include "Assets/AssetManager.hpp"
#include "World/SceneManager.hpp"
#include "Input/InputManager.hpp"
#include "Rendering/RenderSystem.hpp"
#include "Rendering/Renderer.hpp"
#include "Rendering/Window.hpp"
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

Engine::Engine(const std::string& window_name)
    : Macrosystem("Engine")
{
    // Add subsystems and initialize services
    Services::setAssets(addSystem<AssetManager>());
    Services::setResources(addSystem<ResourceManager>());
    Services::setInput(addSystem<InputManager>());
    Services::setRenderer(addSystem<Renderer>());
    Services::setScenes(addSystem<SceneManager>());
    Services::setWindow(addSystem<Window>(window_name));
    Services::setRunService(addSystem<RunService>(on_fixed_update_, on_update_));
    Services::setRenderSystem(addSystem<RenderSystem>());
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

void Engine::onInit() {
    Timer init_timer;

    // Start the engine
    running_ = true;

    // Stop running if the game window closes
    window_close_ = EngineEventDispatcher::subscribe<WindowCloseEvent>([this](const WindowCloseEvent& event) {
        running_ = false;
    });

    // Reset the timer
    timer_.reset();
}

void Engine::onShutdown() {
    EngineEventDispatcher::unsubscribe(std::move(window_close_));
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
    fetchSystem<InputManager>()->startUpdate();
    processSDLEvents_();
    EngineEventQueue::dispatch();
    fetchSystem<InputManager>()->endUpdate();

    // Update gameplay layer
    const double PHYSICS_DT = 1.0 / PHYSICS_FPS;
    while (accumulator_ >= PHYSICS_DT) {
        on_fixed_update_.fire(PHYSICS_DT);
        accumulator_ -= PHYSICS_DT;
    }
    on_update_.fire(frame_dt);
    
    interpolation_alpha_ = accumulator_ / PHYSICS_DT;
    
    // Render
    fetchSystem<Renderer>()->clear({0, 0, 0, 255});
    fetchSystem<RenderSystem>()->render();
    fetchSystem<Renderer>()->present();
    
    // Process object / scene updates
    fetchSystem<SceneManager>()->flushScene();
}

bool Engine::isRunning() const {
    return running_;
}
