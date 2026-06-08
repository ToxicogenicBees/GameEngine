/*
    Engine.hpp

    Declaration for the game engine control class
*/

#pragma once

#include "Core/System/Macrosystem.hpp"
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

class Engine final : public Macrosystem {
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
     * @brief Processes SDL events
     */
    void processSDLEvents_();

protected:
    /**
     * @brief Initialization logic.
     */
    void onInit() final;

    /**
     * @brief Shutdown logic.
     */
    void onShutdown() final;

public:
    /**
     * @brief Constructor
     * 
     * @param window_name The name of the window.
     */
    Engine(const std::string& window_name);

    /**
     * @brief Tick the engine
     */
    void tick();

    /**
     * @brief Gets if the engine is in a running state.
     * 
     * @return If the engine is in a running state.
     */
    bool isRunning() const;
};
