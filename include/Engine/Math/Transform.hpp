/*
    Transform.hpp

    Declaration of a class containing transformation info
*/

#pragma once

#include "Math/Vector2.hpp"

class Transform {
private:
    Vector2 position_ = Vector2::zero();
    Vector2 scale_ = Vector2::one();
    double rotation_ = 0.0;

public:
    /**
     * @brief Constructor.
     * 
     * @param position The transform position.
     * @param scale The transform scale.
     * @param rotation The transform rotation.
     */
    Transform(const Vector2& position, const Vector2& scale, double rotation);

    /**
     * @brief Constructor.
     * 
     * @param position The transform position.
     * @param scale The transform scale.
     */
    Transform(const Vector2& position, const Vector2& scale);

    /**
     * @brief Constructor.
     * 
     * @param position The transform position.
     * @param rotation The transform rotation.
     */
    Transform(const Vector2& position, double rotation);

    /**
     * @brief Constructor.
     * 
     * @param position The transform position.
     */
    Transform(const Vector2& position);

    /**
     * @brief Constructor.
     */
    Transform() = default;

    /**
     * @brief Gets a constant reference to the position of the transform.
     * 
     * @return Constant reference to the transform's position
     */
    const Vector2& position() const;
    
    /**
     * @brief Gets a reference to the position of the transform.
     * 
     * @return Reference to the transform's position
     */
    Vector2& position();

    /**
     * @brief Gets a constant reference to the scale of the transform.
     * 
     * @return Constant reference to the transform's scale
     */
    const Vector2& scale() const;
    
    /**
     * @brief Gets a reference to the scale of the transform.
     * 
     * @return Reference to the transform's scale
     */
    Vector2& scale();

    /**
     * @brief Gets a constant reference to the rotation of the transform.
     * 
     * @return Constant reference to the transform's rotation
     */
    double rotation() const;
    
    /**
     * @brief Gets a reference to the rotation of the transform.
     * 
     * @return Reference to the transform's rotation
     */
    double& rotation();
};
