/*
    BoxCollider2D.cpp

    Implementation of a box collider component
*/

#include "Components/Physics/BoxCollider2D.hpp"
#include "Geometry/Rect.hpp"

BoxCollider2D::BoxCollider2D(const Vector2& center, const Vector2& size)
    : Collider2D(std::type_identity<Rect>{}, center, size) {}
