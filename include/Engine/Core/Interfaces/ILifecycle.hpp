/*
    ILifecycle.hpp

    Abstract class for controlling the lifecycle of objects
*/

#pragma once

class Camera;   // forward declaration

class ILifecycle {
protected:
    /**
     * @brief Custom intialization logic
     */
    virtual void onInit() {};

    /**
     * @brief Custom update logic
     * 
     * @param dt Time between updates
     */
    virtual void onUpdate(double dt) {};

    /**
     * @brief Custom render logic
     * 
     * @param camera Reference to the rendering camera object
     */
    virtual void onRender(Camera& camera) {};

public:
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
     * 
     * @param camera Reference to the rendering camera object
     */
    virtual void render(Camera& camera) = 0;

    /**
     * @brief Destructor
     */
    virtual ~ILifecycle() = default;
};
