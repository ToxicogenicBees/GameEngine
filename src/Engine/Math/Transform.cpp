/*
    Transform.cpp

    Implementation of a class containing transformation info
*/

#include "Math/Transform.hpp"

Transform::Transform(const Vector2& position, const Vector2& scale, double rotation)
    : position_(position), scale_(scale), rotation_(rotation) {}

Transform::Transform(const Vector2& position, const Vector2& scale)
    : position_(position), scale_(scale) {}

Transform::Transform(const Vector2& position, double rotation)
    : position_(position), rotation_(rotation) {}

Transform::Transform(const Vector2& position)
    : position_(position) {}

const Vector2& Transform::position() const {
    return position_;
}

Vector2& Transform::position() {
    return position_;
}

const Vector2& Transform::scale() const {
    return scale_;
}

Vector2& Transform::scale() {
    return scale_;
}

double Transform::rotation() const {
    return rotation_;
}

double& Transform::rotation() {
    return rotation_;
}
