/*
    BoxCollider2D.hpp

    Declaration of a box collider component
*/

#pragma once

#include "Components/Component.hpp"
#include "Geometry/Rect.hpp"
#include "Math/Vector2.hpp"

class BoxCollider2D final : public Component, public Rect {
public:
    /**
     * @brief Constructor.
     * 
     * @param owner The owner of this component.
     * @param center The center of the box
     * @param size The size of the box
     */
    BoxCollider2D(GameObject& owner, const Vector2& center, const Vector2& size);

    /**
     * @brief Constructor.
     * 
     * @param owner The owner of this component.
     */
    BoxCollider2D(GameObject& owner);

    /**
     * @brief Checks if the bounds contains a point.
     * 
     * @param point The point being checked.
     * @return True if the bounds contains the point, false otherwise.
     */
    bool contains(const Vector2& point) const override;
};
