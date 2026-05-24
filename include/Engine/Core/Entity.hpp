/*
    Entity.hpp

    Declaration of an abstract engine entity class
*/

#pragma once

#include "Types/Transform.hpp"

class Entity {
private:
    Transform transform_;
    bool active_ = true;
    bool alive_ = true;

protected:
    virtual void onDestroy() {}

public:
    /**
     * @brief Constructor
     */
    Entity() = default;

    /**
     * @brief Gets a constant reference to this entity's transform.
     * 
     * @return A constant reference to the transform.
     */
    const Transform& transform() const;

    /**
     * @brief Gets a constant reference to this entity's transform.
     * 
     * @return A constant reference to the transform.
     */
    Transform& transform();

    /**
     * @brief Gets if the entity is active.
     * 
     * @return True if the entity is active, false otherwise.
     */
    bool isActive();

    /**
     * @brief Sets the entity's active state.
     * 
     * @param active The desired active state
     */
    void setActive(bool active);

    /**
     * @brief Gets if the entity is alive.
     * 
     * @return True if the entity is alive, false otherwise.
     */
    bool isAlive();

    /**
     * @brief Destroys the entity, marking it as not being alive
     */
    void destroy();

    /**
     * @brief Destructor
     */
    virtual ~Entity() = default;
};
