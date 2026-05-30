/*
    SceneManager.hpp

    Declaration for a scene manager
*/

#pragma once

#include "World/Scene.hpp"
#include <concepts>
#include <memory>

class Window;   // forward declaration

class SceneManager {
private:
    std::unique_ptr<Scene> pending_ = nullptr;
    std::unique_ptr<Scene> active_ = nullptr;

    void processSceneChange_();

public:
    /**
     * @brief Constructor
     */
    SceneManager() = default;

    /**
     * @brief Logic to draw the scene and it's object to a window
     */
    void render();    

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

#include "World/SceneManager.tpp"
