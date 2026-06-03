/*
    SceneManager.hpp

    Declaration for a scene manager
*/

#pragma once

#include "Events/Listeners/UpdateListener.hpp"
#include "World/Scene.hpp"
#include <concepts>
#include <memory>

class Window;   // forward declaration

class SceneManager {
private:
    std::unique_ptr<Scene> pending_ = nullptr;
    std::unique_ptr<Scene> active_ = nullptr;

protected:
    friend class Engine;

    /**
     * @brief Processes a scene change.
     */
    void processSceneChange();

public:
    /**
     * @brief Constructor
     */
    SceneManager() = default;

    /**
     * @brief Flushes the active scene's object buffers.
     */
    void flushScene();

    /**
     * @brief Start a scene transition
     * 
     * @param args Constructor arguments for the new scene
     */
    template<typename Scene_t, typename... Args>
    void loadScene(Args&&... args);
};

#include "World/SceneManager.tpp"
