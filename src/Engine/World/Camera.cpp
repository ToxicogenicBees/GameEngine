/*
    Camera.cpp

    Implementation for a camera class, capable of basic translation and scaling
*/

#include "World/Camera.hpp"
#include "Core/Services.hpp"

double Camera::zoom() const{
    return zoom_;
}

void Camera::setZoom(double zoom) {
    zoom_ = zoom;
}

Vector2 Camera::worldToScreen(const Vector2& world, const Viewport& viewport) const {
    return {
        (world.x - transform().position.x) * zoom_ + viewport.center().x,
        viewport.center().y - (world.y - transform().position.y) * zoom_
    };
}

Vector2 Camera::worldToScreen(const Vector2& world) const {
    return worldToScreen(world, Services::renderer()->viewport());
}

Vector2 Camera::screenToWorld(const Vector2& screen, const Viewport& viewport) const {
    return {
        (screen.x - viewport.center().x) / zoom_ + transform().position.x,
        (viewport.center().y - screen.y) / zoom_ + transform().position.y
    };
}

Vector2 Camera::screenToWorld(const Vector2& screen) const {
    return screenToWorld(screen, Services::renderer()->viewport());
}
