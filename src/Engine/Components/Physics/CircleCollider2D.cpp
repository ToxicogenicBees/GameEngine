/*
    CircleCollider2D.cpp

    Implementation of a circle collider component
*/

#include "Components//Physics/CircleCollider2D.hpp"
#include "World/GameObject.hpp"

CircleCollider2D::CircleCollider2D(GameObject& owner, const Vector2& center, double radius)
    : Component(owner),
      Circle(center, radius)
{}

CircleCollider2D::CircleCollider2D(GameObject& owner)
    : Component(owner) {}

bool CircleCollider2D::contains(const Vector2& point) const {
    return Circle::contains(point - owner()->transform().position());
}