/*
    BoxCollider2D.cpp

    Implementation of a box collider component
*/

#include "Components/Physics/BoxCollider2D.hpp"
#include "World/GameObject.hpp"

BoxCollider2D::BoxCollider2D(GameObject& owner, const Vector2& center, const Vector2& size)
    : Component(owner),
      Rect(center, size) 
{}

BoxCollider2D::BoxCollider2D(GameObject& owner)
    : Component(owner) {}

bool BoxCollider2D::contains(const Vector2& point) const {
    return Rect::contains(point - owner()->transform().position());
}