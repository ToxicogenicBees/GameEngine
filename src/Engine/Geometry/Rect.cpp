/*
    Rect.cpp

    Implementation for a rectangular bounding box
*/

#include "Geometry/Rect.hpp"

Rect::Rect(Vector2 center, Vector2 size) 
    : center_(center), size_(size) {}

void Rect::setCenter(Vector2 center) {
    center_ = center;
}

void Rect::setSize(Vector2 size) {
    size_ = size;
}

Vector2 Rect::center() const {
    return center_ + 0.5 * size_;
}

Vector2 Rect::size() const {
    return size_;
}

bool Rect::contains(Vector2 point) const {
    auto half_size = 0.5 * size_;
    return point.x >= center_.x - half_size.x
        && point.x <= center_.x + half_size.x
        && point.y >= center_.y - half_size.y
        && point.y <= center_.y + half_size.y;
}
