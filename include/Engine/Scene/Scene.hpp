/*
    Scene.hpp

    Declaration for a scene class, in charge of storing game objects
*/

#pragma once

#include "Core/Interfaces/ILifecycle.hpp"
#include "Events/EventSubscription.hpp"
#include "Rendering/Camera.hpp"
#include "Rendering/Window.hpp"
#include <algorithm>
#include <vector>
#include <memory>

class GameObject; // forward declaration

class Scene {
private:
    std::vector<std::unique_ptr<GameObject>> objects_;
    std::vector<std::unique_ptr<GameObject>> pending_create_;
    std::vector<GameObject*> pending_destroy_;

    std::vector<EventSubscription> subscriptions_;

    Camera camera_;
    
    /**
     * @brief Add all new objects to the scene
     */
    void processCreations_();
    
    /**
     * @brief Remove all destroyed objects from the scene
     */
    void processDestructions_();
    
protected:
    friend class SceneManager;

    /**
     * @brief Customizable initialization behavior
     */
    virtual void onInit() {}

    /**
     * @brief Customizable update behavior
     * 
     * @param dt The time difference since the last update
     */
    virtual void onUpdate(double dt) {}

    /**
     * @brief Customizable render behavior
     */
    virtual void onRender() {}

    /**
     * @brief Customizable unload behavior
     */
    virtual void onUnload() {}

    /**
     * @brief Subscribe to an engine event
     * 
     * @param func The event callback function
     */
    template <typename Event_t, typename Func>
    void subscribe(Func&& func);

public:
    /**
     * @brief Constructor
     */
    Scene() = default;

    /**
     * @brief Initialize the object
     */
    void init();

    /**
     * @brief Update the object
     * 
     * @param dt Time between updates
     */
    void update(double dt);

    /**
     * @brief Render the object
     */
    void render();

    /**
     * @brief Logic to unload the scene
     */
    void unload();

    /**
     * @brief Gets a reference to the scene's camera
     * 
     * @return A reference to the scene's camera
     */
    Camera& camera();

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

    /**
     * @brief Destructor.
     */
    virtual ~Scene() = default;
};

#include "Scene/Scene.tpp"
