/*
    Rect.hpp

    Declaration for a rectangular bounding box
*/

#pragma once

#include "Geometry/IBoundingBox.hpp"
#include "Types/Vector2.hpp"
#include "Types/Size.hpp"

class Rect : public IBoundingBox {
private:
    Vector2 center_;
    Size size_;

public:
    /**
     * @brief Constructor
     * 
     * @param center The center of the box
     * @param size The size of the box
     */
    Rect(const Vector2& center, const Size& size);

    /**
     * @brief Constructor
     * 
     * @param p1 One corner the box
     * @param p2 The other corner of the box
     */
    Rect(const Vector2& p1, const Vector2& p2);

    /**
     * @brief Sets the center of the bounds.
     * 
     * @param center The desired center of the bounds.
     */
    void setCenter(const Vector2& center) override;

    /**
     * @brief Gets the size of the bounds.
     *
     * @return The size of the bounds.
     */
    Size size() const;

    /**
     * @brief Gets the center of the bounds.
     * 
     * @return The center of the bounds.
     */
    Vector2 center() const override;

    /**
     * @brief Checks if the bounds contains a point.
     * 
     * @param point The point being checked.
     * @return True if the bounds contains the point, false otherwise.
     */
    bool contains(const Vector2& point) const override;
};
