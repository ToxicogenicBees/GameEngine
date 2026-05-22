/*
    Scene.hpp

    Declaration for a scene class, in charge of storing game objects
*/

#pragma once

#include "Rendering/Window.hpp"
#include <algorithm>
#include <vector>
#include <memory>

class GameObject; // forward declaration

class Scene {
private:
    std::vector<std::unique_ptr<GameObject>> objects_;
    std::vector<GameObject*> pending_destroy_;

    /**
     * @brief Remove all destroyed objects from the scene
     */
    void processDestructions();

public:
    /**
     * @brief Constructor
     */
    Scene() = default;

    /**
     * @brief Initialize the scene and its objects
     */
    void init();

    /**
     * @brief Update the scene and its objects
     * 
     * @param dt The time difference since the last update
     */
    void update(float dt);

    /**
     * @brief Logic to draw the scene and it's object to a window
     * 
     * @param window The window the object is being drawn to
     */
    void render(Window& window);

    /**
     * @brief Create a game object in this scene.
     * 
     * @param args Constructor arguments for the desired game object
     * 
     * @return object The created object.
     */
    template<typename T, typename... Args>
    T* create(Args&&... args);

    /**
     * @brief Remove a game object from the scene.
     * 
     * @param object The object being removed
     */
    void destroy(GameObject* obj);
};

#include "Game/Scene.tpp"
