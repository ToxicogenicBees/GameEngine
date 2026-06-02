/*
    CircleCollider2D.cpp

    Implementation of a circle collider component
*/

#include "Components//Physics/CircleCollider2D.hpp"
#include "World/GameObject.hpp"

CircleCollider2D::CircleCollider2D(const Vector2& center, double radius)
    : Circle(center, radius) {}

bool CircleCollider2D::contains(const Vector2& point) const {
    return Circle::contains(point - owner_->transform().position());
}