/*
    Engine.hpp

    Declaration for the game engine control class
*/

#pragma once

#include "Events/EventSubscription.hpp"
#include "World/SceneManager.hpp"
#include "Assets/AssetManager.hpp"
#include "Resources/ResourceManager.hpp"
#include "Input/InputManager.hpp"
#include "Rendering/Renderer.hpp"
#include "Rendering/Window.hpp"
#include "Geometry/Size.hpp"
#include "Utility/Timer.hpp"
#include <string>

class Engine {
private:
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
    std::unique_ptr<EventSubscription> window_close_;
    Timer timer_;
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
