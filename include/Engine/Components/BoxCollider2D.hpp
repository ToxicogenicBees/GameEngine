/*
    BoxCollider2D.hpp

    Declaration of a box collider component
*/

#pragma once

#include "Components/Collider2D.hpp"
#include "Types/Vector2.hpp"

class BoxCollider2D : public Collider2D {
public:
    /**
     * @brief Constructor.
     * 
     * @param center The center of the box
     * @param size The size of the box
     */
    BoxCollider2D(const Vector2& center, const Vector2& size);
};
