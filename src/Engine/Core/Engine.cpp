/*
    Engine.cpp

    Implementation for the game engine control class
*/

#include "Core/Engine.hpp"

// Event processing
#include "Events/EventTypes/MouseButtonEvent.hpp"
#include "Events/EventTypes/WindowCloseEvent.hpp"
#include "Events/EventTypes/MouseMotionEvent.hpp"
#include "Events/EventTypes/KeyEvent.hpp"
#include "Events/EngineEventDispatcher.hpp"
#include "Events/EngineEventQueue.hpp"
#include <SDL3/SDL.h>

// Subsystems
#include "Resources/ResourceManager.hpp"
#include "Assets/AssetManager.hpp"
#include "World/SceneManager.hpp"
#include "Input/InputManager.hpp"
#include "Rendering/RenderSystem.hpp"
#include "Rendering/Renderer.hpp"
#include "Rendering/Window.hpp"
#include "Core/RunService.hpp"
#include "Core/Services.hpp"

// Asset loaders
#include "Assets/Loaders/ShaderAssetLoader.hpp"
#include "Assets/Loaders/ImageLoader.hpp"
#include "Assets/Loaders/FileLoader.hpp"

// Resource loaders
#include "Resources/Loaders/TextureLoader.hpp"

namespace {
    constexpr size_t PHYSICS_FPS = 60;
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
        switch(event.type) {
            // Mouse pressed
            case (SDL_EVENT_MOUSE_BUTTON_DOWN): 
            case (SDL_EVENT_MOUSE_BUTTON_UP): {
                auto pressed = event.type == SDL_EVENT_MOUSE_BUTTON_DOWN;
                Vector2 pos = {event.button.x, event.button.y};
                if (event.button.button == SDL_BUTTON_LEFT)
                    EngineEventQueue::push(std::make_unique<MouseButtonEvent>(MouseButton::LEFT, pressed, pos));
                else if (event.button.button == SDL_BUTTON_RIGHT)
                    EngineEventQueue::push(std::make_unique<MouseButtonEvent>(MouseButton::RIGHT, pressed, pos));
                else if (event.button.button == SDL_BUTTON_MIDDLE)
                    EngineEventQueue::push(std::make_unique<MouseButtonEvent>(MouseButton::MIDDLE, pressed, pos));
                break;
            }

            // Mouse moved
            case (SDL_EVENT_MOUSE_MOTION): {
                Vector2 pos = {event.motion.x, event.motion.y};
                EngineEventQueue::push(std::make_unique<MouseMotionEvent>(pos));
                break;
            }

            // Quit
            case (SDL_EVENT_QUIT): {
                EngineEventQueue::push(std::make_unique<WindowCloseEvent>());
                break;
            }
        }
    }
}

void Engine::registerAssetLoaders_() {
    auto* asset_manager = fetchSystem<AssetManager>();

    asset_manager->addLoader<ShaderAssetLoader>();
    asset_manager->addLoader<ImageLoader>();
    asset_manager->addLoader<FileLoader>();
}

void Engine::registerResourceLoaders_() {
    auto* resource_manager = fetchSystem<ResourceManager>();

    resource_manager->addLoader<TextureLoader>();
}

void Engine::onInit() {
    // Register loaders
    registerAssetLoaders_();
    registerResourceLoaders_();

    // Start the engine
    running_ = true;

    // Stop running if the game window closes
    window_close_ = EngineEventDispatcher::subscribe<WindowCloseEvent>([this](const WindowCloseEvent& event) {
        running_ = false;
    });

    // Reset the timer
    tick_timer_.reset();
}

void Engine::onShutdown() {
    EngineEventDispatcher::unsubscribe(std::move(window_close_));
}

void Engine::tick() {
    // Start frame timer
    Timer frame_timer;

    // Calculate time difference
    double frame_dt = tick_timer_.seconds();
    tick_timer_.reset();

    // Update accumulator
    accumulator_ += frame_dt;

    // Input management
    fetchSystem<InputManager>()->beginFrame();
    processSDLEvents_();
    EngineEventQueue::dispatch();
    fetchSystem<InputManager>()->endFrame();

    // Update gameplay layer
    const double PHYSICS_DT = 1.0 / PHYSICS_FPS;
    while (accumulator_ >= PHYSICS_DT) {
        on_fixed_update_.fire(PHYSICS_DT);
        accumulator_ -= PHYSICS_DT;
    }
    on_update_.fire(frame_dt);
    
    interpolation_alpha_ = accumulator_ / PHYSICS_DT;
    
    // Render
    fetchSystem<Renderer>()->beginFrame();
    fetchSystem<RenderSystem>()->render();
    fetchSystem<Renderer>()->endFrame();
    
    // Process object / scene updates
    fetchSystem<SceneManager>()->flushScene();
}

bool Engine::isRunning() const {
    return running_;
}
