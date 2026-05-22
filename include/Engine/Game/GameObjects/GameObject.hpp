/*
    GameObject.hpp

    Declaration for a game object that can be rendered on the screen
*/

#pragma once

#include "Assets/Asset.hpp"
#include "Rendering/Window.hpp"
#include "Types/Vector2.hpp"
#include "Types/Size.hpp"
#include <filesystem>
#include <memory>

class Scene; // forward declaration

class GameObject {
private:
    Scene* scene_ = nullptr;
    bool alive_ = true;

public:
    friend class Scene;

    Vector2 position = Vector2::zero();

    /**
     * @brief Constructor
     */
    GameObject() = default;

    /**
     * @brief Initialization function ran once the object enters the game scene.
     */
    virtual void init() {}

    /**
     * @brief Update function ran once every game tick.
     * 
     * @param dt Time difference, in seconds, since last update.
     */
    virtual void update(double dt) {}

    /**
     * @brief Logic to handle removing the object from a scene.
     */
    virtual void onDestroy() {}

    /**
     * @brief Logic to draw the object to a window
     * 
     * @param window The window the object is being drawn to
     */
    virtual void render(Window& window) {}

    /**
     * @brief Gets if the game object is alive.
     * 
     * @return True if the game object is alive, false otherwise.
     */
    bool isAlive() const {
        return alive_;
    }

    /**
     * @brief Destructor
     */
    virtual ~GameObject() = default;
};
