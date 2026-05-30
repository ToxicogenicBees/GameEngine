/*
    Circle.cpp

    Implementation for a circular bounding box
*/

#include "Geometry/Circle.hpp"

Circle::Circle(const Vector2& center, double radius) 
    : center_(center), radius_(radius) {}

void Circle::setCenter(const Vector2& center) {
    center_ = center;
}

void Circle::setSize(double size) {
    radius_ = size;
}

Vector2 Circle::center() const {
    return center_;
}

double Circle::size() const {
    return radius_;
}

bool Circle::contains(const Vector2& point) const {
    return std::fabs((point - center_).magnitude() - radius_) <= 1e-8;
}
