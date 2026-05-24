/*
    Camera.hpp

    Declaration for a camera class, capable of basic translation and scaling
*/

#pragma once

#include "Types/Vector2.hpp"
#include "Core/Object.hpp"

class Camera : public Object {
private:
    double zoom_ = 1;

public:
    Camera() = default;

    double zoom() const;
    void setZoom(double zoom);

    Vector2 worldToScreen(const Vector2& world) const;
    Vector2 screenToWorld(const Vector2& world) const;
};
