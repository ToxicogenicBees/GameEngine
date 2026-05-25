/*
    BoxCollider2D.cpp

    Implementation of a box collider component
*/

#include "Components/BoxCollider2D.hpp"
#include "Geometry/Rect.hpp"

BoxCollider2D::BoxCollider2D(const Vector2& center, const Size& size)
    : Collider2D(std::type_identity<Rect>{}, center, size) {}

BoxCollider2D::BoxCollider2D(const Vector2& p1, const Vector2& p2)
    : Collider2D(std::type_identity<Rect>{}, p1, p2) {}
