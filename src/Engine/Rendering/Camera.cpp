/*
    Camera.cpp

    Implementation for a camera class, capable of basic translation and scaling
*/

#include "Rendering/Camera.hpp"
#include "Core/Services.hpp"

double Camera::zoom() const{
    return zoom_;
}

void Camera::setZoom(double zoom) {
    zoom_ = zoom;
}

Vector2 Camera::worldToScreen(const Vector2& world, const Viewport& viewport) const {
    return (world - transform().position) * zoom_ + viewport.center();
}

Vector2 Camera::worldToScreen(const Vector2& world) const {
    return (world - transform().position) * zoom_ + Services::renderer()->viewport().center();
}

Vector2 Camera::screenToWorld(const Vector2& screen, const Viewport& viewport) const {
    return ((screen - viewport.center()) / zoom_) + transform().position;
}

Vector2 Camera::screenToWorld(const Vector2& screen) const {
    return ((screen - Services::renderer()->viewport().center()) / zoom_) + transform().position;
}
