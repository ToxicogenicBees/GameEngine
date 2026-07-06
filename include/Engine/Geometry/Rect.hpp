/*
    Rect.hpp

    Declaration for a rectangular bounding box
*/

#pragma once

#include "Geometry/Interfaces/IBoundingBox.hpp"
#include "Math/Vector2.hpp"

class Rect : public IBoundingBox {
private:
    Vector2 center_ = Vector2::zero();
    Vector2 size_ = Vector2::zero();

public:
    /**
     * @brief Constructor
     * 
     * @param center The center of the box
     * @param size The size of the box
     */
    Rect(Vector2 center, Vector2 size);

    /**
     * @brief Constructor.
     */
    Rect() = default;

    /**
     * @brief Sets the center of the bounds.
     * 
     * @param center The desired center of the bounds.
     */
    void setCenter(Vector2 center) final;

    /**
     * @brief Sets the size of the bounds.
     * 
     * @param size The desired size of the bounds.
     */
    void setSize(Vector2 size);

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
    Vector2 size() const;

    /**
     * @brief Checks if the bounds contains a point.
     * 
     * @param point The point being checked.
     * @return True if the bounds contains the point, false otherwise.
     */
    bool contains(Vector2 point) const override;
};
