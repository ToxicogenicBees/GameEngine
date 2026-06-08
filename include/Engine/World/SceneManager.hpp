/*
    SceneManager.hpp

    Declaration for a scene manager
*/

#pragma once

#include "Core/System/Subsystem.hpp"
#include "Events/Listeners/UpdateListener.hpp"
#include "World/Scene.hpp"
#include <concepts>
#include <memory>

class SceneManager final : public Subsystem {
private:
    std::unique_ptr<Scene> pending_ = nullptr;
    std::unique_ptr<Scene> active_ = nullptr;

    /**
     * @brief Processes a scene change.
     */
    void processSceneChange_();

public:
    /**
     * @brief Constructor.
     */
    SceneManager();

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
