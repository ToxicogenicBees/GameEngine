/*
    Collider2D.cpp

    Implementation for an abstract 2D collider component
*/

#include "Components/Collider2D.hpp"
#include "Core/GameObject.hpp"

IBoundingBox* Collider2D::bounds() const {
    return bounds_.get();
}

bool Collider2D::contains(const Vector2& point) const {
    return bounds_->contains(point - owner_->transform().position);
}
