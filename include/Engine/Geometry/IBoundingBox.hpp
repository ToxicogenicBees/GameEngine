/*
    IBoundingBox.hpp

    Interface for a bounding box class
*/

#pragma once

#include "Math/Vector2.hpp"

struct IBoundingBox {
    /**
     * @brief Sets the center of the bounds.
     * 
     * @param center The desired center of the bounds.
     */
    virtual void setCenter(const Vector2& center) = 0;

    /**
     * @brief Gets the center of the bounds.
     * 
     * @return The center of the bounds.
     */
    virtual Vector2 center() const = 0;

    /**
     * @brief Checks if the bounds contains a point.
     * 
     * @param point The point being checked.
     * @return True if the bounds contains the point, false otherwise.
     */
    virtual bool contains(const Vector2& point) const = 0;

    /**
     * @brief Destructor.
     */
    virtual ~IBoundingBox() = default;
};
