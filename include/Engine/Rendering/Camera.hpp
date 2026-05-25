/*
    Camera.hpp

    Declaration for a camera class, capable of basic translation and scaling
*/

#pragma once

#include "Types/Viewport.hpp"
#include "Core/Entity.hpp"

class Camera : public Entity {
private:
    double zoom_ = 1;

public:
    Camera() = default;

    double zoom() const;
    void setZoom(double zoom);

    Vector2 worldToScreen(const Vector2& world, const Viewport& viewport) const;
    Vector2 screenToWorld(const Vector2& world, const Viewport& viewport) const;
};
