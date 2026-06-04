/*
    Engine.hpp

    Declaration for the game engine control class
*/

#pragma once

#include "Core/RunService.hpp"
#include "Events/EventSubscription.hpp"
#include "Events/BindableEvent.hpp"
#include "World/SceneManager.hpp"
#include "Assets/AssetManager.hpp"
#include "Resources/ResourceManager.hpp"
#include "Input/InputManager.hpp"
#include "Rendering/RenderSystem.hpp"
#include "Rendering/Renderer.hpp"
#include "Rendering/Window.hpp"
#include "Geometry/Size.hpp"
#include "Utility/Timer.hpp"
#include <string>

class Engine {
private:
    // Events
    BindableEvent<double> on_fixed_update_;
    BindableEvent<double> on_update_;

    // Rendering
    Window window_;
    Renderer renderer_;
    RenderSystem render_system_;

    // Services
    AssetManager assets_;
    ResourceManager resources_;
    InputManager input_;

    // Scene manager
    SceneManager scene_manager_;

    // RunService
    RunService run_service_;

    // Timing
    double interpolation_alpha_ = 0;
    double accumulator_ = 0;
    Timer timer_;
    
    // Execution state
    std::unique_ptr<EventSubscription> window_close_;
    bool running_;

    /**
     * @brief Initialize the engine
     */
    void init_();

    /**
     * @brief Shutdown the engine
     */
    void shutdown_();

    /**
     * @brief Tick the engine
     */
    void tick_();

    /**
     * @brief Processes SDL events
     */
    void processSDLEvents_();

public:
    /**
     * @brief Constructor
     * 
     * @param name The name of the window.
     */
    Engine(const std::string& name);

    /**
     * @brief Run the engine
     */
    void run();
};
