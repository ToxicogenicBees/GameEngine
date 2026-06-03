/*
    CircleCollider2D.hpp

    Declaration of a circle collider component
*/

#pragma once

#include "Components/Component.hpp"
#include "Geometry/Circle.hpp"
#include "Math/Vector2.hpp"

class CircleCollider2D final : public Component, public Circle {
public:
    /**
     * @brief Constructor.
     * 
     * @param owner The owner of this component.
     * @param center The center of the circle
     * @param radius The radius of the circle
     */
    CircleCollider2D(GameObject& owner, const Vector2& center, double radius);
    
    /**
     * @brief Constructor.
     * 
     * @param owner The owner of this component.
     */
    CircleCollider2D(GameObject& owner);

    /**
     * @brief Checks if the bounds contains a point.
     * 
     * @param point The point being checked.
     * @return True if the bounds contains the point, false otherwise.
     */
    bool contains(const Vector2& point) const override;
};
