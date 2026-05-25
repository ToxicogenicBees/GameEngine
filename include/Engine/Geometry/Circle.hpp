/*
    Circle.hpp

    Declaration for a circular bounding box
*/

#pragma once

#include "Geometry/IBoundingBox.hpp"
#include "Types/Vector2.hpp"

class Circle : public IBoundingBox {
private:
    Vector2 center_;
    double radius_;

public:
    /**
     * @brief Constructor
     * 
     * @param 
     */
    Circle(const Vector2& position, double radius);

    /**
     * @brief Sets the center of the bounds.
     * 
     * @param center The desired center of the bounds.
     */
    void setCenter(const Vector2& center) override;

    /**
     * @brief Gets the size (radius) of the bounds.
     *
     * @return The size (radius) of the bounds.
     */
    double size() const;

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
