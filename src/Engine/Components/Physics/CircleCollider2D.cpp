/*
    CircleCollider2D.cpp

    Implementation of a circle collider component
*/

#include "Components//Physics/CircleCollider2D.hpp"
#include "Geometry/Circle.hpp"

CircleCollider2D::CircleCollider2D(const Vector2& center, double radius)
    : Collider2D(std::type_identity<Circle>{}, center, radius) {}
