/*
    Camera.hpp

    Declaration for a camera class, capable of basic translation and scaling
*/

#pragma once

#include "Rendering/Viewport.hpp"
#include "Core/Entity.hpp"

class Camera : public Entity {
private:
    double zoom_ = 1;

public:
    /**
     * @brief Constructor.
     */
    Camera() = default;

    /**
     * @brief Gets the camera's current zoom.
     * 
     * @return The camera's zoom.
     */
    double zoom() const;

    /**
     * @brief Sets the camera's zoom.
     * 
     * @param zoom The desired zoom.
     */
    void setZoom(double zoom);

    /**
     * @brief Converts a world position to a screen position.
     * 
     * @param world The world coordinate being converted.
     * @param viewport The relative camera viewport.
     */
    Vector2 worldToScreen(Vector2 world, const Viewport& viewport) const;

    /**
     * @brief Converts a world position to a screen position, using the logical renderer viewport.
     * 
     * @param world The world coordinate being converted.
     */
    Vector2 worldToScreen(Vector2 world) const;

    /**
     * @brief Converts a screen position to a world position.
     * 
     * @param screen The screen coordinate being converted.
     * @param viewport The relative camera viewport.
     */
    Vector2 screenToWorld(Vector2 world, const Viewport& viewport) const;

    /**
     * @brief Converts a screen position to a world position, using the logical renderer viewport.
     * 
     * @param screen The screen coordinate being converted.
     */
    Vector2 screenToWorld(Vector2 world) const;
};
