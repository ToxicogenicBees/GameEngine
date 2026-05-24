/*
    ILifecycle.hpp

    Interface for controlling the lifecycle of objects
*/

#pragma once

class Camera;   // forward declaration

struct ILifecycle {
    /**
     * @brief Initialize the object
     */
    virtual void init() = 0;

    /**
     * @brief Update the object
     * 
     * @param dt Time between updates
     */
    virtual void update(double dt) = 0;

    /**
     * @brief Render the object
     */
    virtual void render(Camera& camera) = 0;

    /**
     * @brief Destructor
     */
    virtual ~ILifecycle() = default;
};
