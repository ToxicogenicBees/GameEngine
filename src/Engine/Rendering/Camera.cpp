/*
    Camera.cpp

    Implementation for a camera class, capable of basic translation and scaling
*/

#include "Rendering/Camera.hpp"

double Camera::zoom() const{
    return zoom_;
}

void Camera::setZoom(double zoom) {
    zoom_ = zoom;
}

Vector2 Camera::worldToScreen(const Vector2& world) const {
    return (world - transform().position) * zoom();
}

Vector2 Camera::screenToWorld(const Vector2& screen) const {
    return (screen / zoom()) + transform().position;
}
