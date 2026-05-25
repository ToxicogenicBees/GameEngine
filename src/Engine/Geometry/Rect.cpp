/*
    Rect.cpp

    Implementation for a rectangular bounding box
*/

#include "Geometry/Rect.hpp"

Rect::Rect(const Vector2& center, const Size& size) 
    : center_(center), size_(size) {}

Rect::Rect(const Vector2& p1, const Vector2& p2) 
    : center_(0.5 * (p1 + p2)), 
      size_({std::fabs(p1.x - p2.x), std::fabs(p1.y - p2.y)}) {}

Size Rect::size() const {
    return size_;
}

void Rect::setCenter(const Vector2& center) {
    center_ = center;
}

Vector2 Rect::center() const {
    return center_ + Vector2{0.5 * size_.width(), 0.5 * size_.height()};
}

bool Rect::contains(const Vector2& point) const {
    auto half_size = 0.5 * size_;
    return point.x >= center_.x - half_size.width()
        && point.x <= center_.x + half_size.width()
        && point.y >= center_.y - half_size.height()
        && point.y <= center_.y + half_size.height();
}
