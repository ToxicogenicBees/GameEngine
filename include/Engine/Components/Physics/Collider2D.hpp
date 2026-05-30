/*
    Collider2D.hpp

    Declaration for an abstract 2D collider component
*/

#pragma once

#include "Components/Component.hpp"
#include "Geometry/IBoundingBox.hpp"
#include <type_traits>
#include <memory>

class Collider2D : public Component {
private:
    std::unique_ptr<IBoundingBox> bounds_;

public:
    /**
     * @brief Constructor.
     * 
     * @param args Constructor parameters for the desired bounding box.
     */
    template<typename BoundingBox_t, typename... Args>
    Collider2D(std::type_identity<BoundingBox_t>, Args&&... args);

    /**
     * @brief Gets the bounding box of this collider.
     * 
     * @return The bounding box of the collider.
     */
    IBoundingBox* bounds() const;

    /**
     * @brief Gets whether a point is within the collider.
     * 
     * @return True if the point is within the collider, and false otherwise.
     */
    bool contains(const Vector2& point) const;
};

#include "Components/Physics/Collider2D.tpp"
