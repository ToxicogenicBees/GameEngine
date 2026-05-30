/*
    Circle.hpp

    Declaration for a circular bounding box
*/

#pragma once

#include "Geometry/IBoundingBox.hpp"
#include "Math/Vector2.hpp"

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
     * @brief Sets the size of the bounds.
     * 
     * @param size The desired size of the bounds.
     */
    void setSize(double size);

    /**
     * @brief Gets the center of the bounds.
     * 
     * @return The center of the bounds.
     */
    Vector2 center() const override;

    /**
     * @brief Gets the size of the bounds.
     *
     * @return The size of the bounds.
     */
    double size() const;

    /**
     * @brief Checks if the bounds contains a point.
     * 
     * @param point The point being checked.
     * @return True if the bounds contains the point, false otherwise.
     */
    bool contains(const Vector2& point) const override;
};
