/*
    Component.hpp

    Declaration for modular components to add to game objects
*/

#pragma once

#include "Core/Interfaces/ILifecycle.hpp"
#include "Core/Object.hpp"

class GameObject;   // forward declaration
class Window;       // forward declaration

class Component : public ILifecycle, public Object {
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
    void init() final;

    /**
     * @brief Update the object
     * 
     * @param dt Time between updates
     */
    void update(double dt) final;

    /**
     * @brief Render the object
     */
    void render(Camera& camera) final;
};
