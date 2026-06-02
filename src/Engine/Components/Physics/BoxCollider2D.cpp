/*
    BoxCollider2D.cpp

    Implementation of a box collider component
*/

#include "Components/Physics/BoxCollider2D.hpp"
#include "World/GameObject.hpp"

BoxCollider2D::BoxCollider2D(const Vector2& center, const Vector2& size)
    : Rect(center, size) {}

bool BoxCollider2D::contains(const Vector2& point) const {
    return Rect::contains(point - owner_->transform().position());
}