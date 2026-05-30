/*
    CircleCollider2D.hpp

    Declaration of a circle collider component
*/

#pragma once

#include "Components/Collider2D.hpp"
#include "Geometry/Circle.hpp"
#include "Types/Vector2.hpp"

class CircleCollider2D final : public Collider2D {
public:
    /**
     * @brief Constructor.
     * 
     * @param center The center of the circle
     * @param radius The radius of the circle
     */
    CircleCollider2D(const Vector2& center, double radius);
};
