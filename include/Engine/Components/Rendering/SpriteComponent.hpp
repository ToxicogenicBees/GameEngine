/*
    SpriteComponent.hpp

    Declaration for a component containing a 2D sprite
*/

#pragma once

#include "Components/Component.hpp"
#include "Graphics/Sprites/Sprite.hpp"
#include "Math/Vector2.hpp"
#include <string>

class SpriteComponent final : public Component {
private:
    Vector2 anchor_ = Vector2::zero();
    Sprite sprite_;

protected:
    /**
     * @brief Custom render logic
     * 
     * @param camera Reference to the rendering camera object
     */
    void onRender(Camera& camera) override;

public:
    /**
     * @brief Constructor.
     * 
     * @param texture The desired texture.
     */
    SpriteComponent(const Sprite& sprite);

    /**
     * @brief Constructor.
     */
    SpriteComponent() = default;

    /**
     * @brief Set the texture of this component.
     * 
     * @param texture The desired texture.
     */
    void setSprite(const Sprite& sprite);

    /**
     * @brief Set the sprite of this component.
     */
    Sprite sprite() const;

    /**
     * @brief Gets the sprite's anchor.
     * 
     * @return A the sprite's anchor.
     */
    Vector2 anchor() const;
    
    /**
     * @brief Sets the sprite's anchor.
     * 
     * @param offset The desired anchor.
     */
    void setAnchor(const Vector2& anchor);
    
    /**
     * @brief Gets the size of the sprite.
     * 
     * @return The size of the sprite.
     */
    Size size() const;
};
