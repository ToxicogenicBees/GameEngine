/*
    BoxCollider2D.hpp

    Declaration of a box collider component
*/

#pragma once

#include "Components/Physics/Collider2D.hpp"
#include "Math/Vector2.hpp"

class BoxCollider2D final : public Collider2D {
public:
    /**
     * @brief Constructor.
     * 
     * @param center The center of the box
     * @param size The size of the box
     */
    BoxCollider2D(const Vector2& center, const Vector2& size);
};
