/*
    Object.hpp

    Declaration of an abstract engine object class
*/

#pragma once

#include "Types/Transform.hpp"

class Object {
private:
    Transform transform_;

public:
    /**
     * @brief Constructor
     */
    Object() = default;

    /**
     * @brief Gets a constant reference to this object's transform
     * 
     * @return A constant reference to the transform
     */
    const Transform& transform() const;

    /**
     * @brief Gets a constant reference to this object's transform
     * 
     * @return A constant reference to the transform
     */
    Transform& transform();
};
