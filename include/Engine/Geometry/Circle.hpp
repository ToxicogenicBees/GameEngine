/*
    Circle.hpp

    Declaration for a circular bounding box
*/

#pragma once

#include "Geometry/IBoundingBox.hpp"
#include "Math/Vector2.hpp"

class Circle : public IBoundingBox {
private:
    Vector2 center_ = Vector2::zero();
    double radius_ = 0;

public:
    /**
     * @brief Constructor.
     * 
     * @param center The center of the circle.
     * @param radius The radius of the circle.
     */
    Circle(const Vector2& center, double radius);

    /**
     * @brief Constructor.
     */
    Circle() = default;

    /**
     * @brief Sets the center of the bounds.
     * 
     * @param center The desired center of the bounds.
     */
    void setCenter(const Vector2& center) final;

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
    Vector2 center() const final;

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
