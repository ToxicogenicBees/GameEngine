/*
    Engine.hpp

    Declaration for the game engine control class
*/

#pragma once

#include "World/SceneManager.hpp"
#include "Assets/AssetManager.hpp"
#include "Resources/ResourceManager.hpp"
#include "Input/InputManager.hpp"
#include "Rendering/Renderer.hpp"
#include "Rendering/Window.hpp"
#include "Geometry/Size.hpp"
#include <chrono>
#include <string>

class Engine {
private:
    using Clock = std::chrono::high_resolution_clock;
    using Sample = std::chrono::time_point<Clock>;

    // Rendering
    Window window_;
    Renderer renderer_;

    // Services
    AssetManager assets_;
    ResourceManager resources_;
    InputManager input_;

    // Scene manager
    SceneManager scene_manager_;

    // Execution state
    Sample prev_time_;
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
