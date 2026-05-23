/*
    Component.hpp

    Declaration for modular components to add to game objects
*/

#pragma once

#include "Core/ILifecycle.hpp"

class GameObject;   // forward declaration
class Window;       // forward declaration

class Component : public ILifecycle {
protected:
    GameObject* owner_ = nullptr;

    friend class GameObject;

public:
    /**
     * @brief Constructor
     */
    Component() = default;

    /**
     * @brief Initialize the object
     */
    void init() override {}

    /**
     * @brief Update the object
     * 
     * @param dt Time between updates
     */
    void update(double dt) override {}

    /**
     * @brief Render the object
     * 
     * @param renderer Reference to the renderer being rendered to
     */
    void render(Renderer& renderer) override {}
};
