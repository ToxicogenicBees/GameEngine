/*
    SceneManager.hpp

    Declaration for a scene manager
*/

#pragma once

#include "Core/EngineContext.hpp"
#include "Scene/Scene.hpp"
#include <concepts>
#include <memory>

class Window;   // forward declaration

class SceneManager {
private:
    std::unique_ptr<Scene> pending_ = nullptr;
    std::unique_ptr<Scene> active_ = nullptr;
    EngineContext& context_;

    void processSceneChange_();

public:
    /**
     * @brief Constructor
     * 
     * @param context A reference to the engine's context
     */
    SceneManager(EngineContext& context);

    /**
     * @brief Logic to draw the scene and it's object to a window
     * 
     * @param renderer The renderer the object is being drawn to
     */
    void render(Renderer& renderer);    

    /**
     * @brief Update the scene and its objects
     * 
     * @param dt The time difference since the last update
     */
    void update(double dt);

    /**
     * @brief Start a scene transition
     * 
     * @param args Constructor arguments for the new scene
     */
    template<typename Scene_t, typename... Args>
    void loadScene(Args&&... args);
};

#include "Scene/SceneManager.tpp"
