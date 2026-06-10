/*
    SpriteComponent.hpp

    Declaration for a component containing a 2D sprite
*/

#pragma once

#include "Components/Component.hpp"
#include "Graphics/Sprites/Sprite.hpp"
#include "Math/Vector2.hpp"

class SpriteComponent final : public Component, public Sprite {
private:
    Vector2 anchor_ = Vector2::zero();
    Sprite sprite_;

public:
    /**
     * @brief Constructor.
     * 
     * @param owner The owner of this component.
     * @param texture The desired texture
     * @param offset The offset from the top-left of the texture.
     * @param size The size of the sprite.
     */
    SpriteComponent(GameObject& owner, TextureHandle texture, const Vector2i& offset, const Size& size);

    /**
     * @brief Constructor.
     * 
     * @param owner The owner of this component.
     * @param texture The desired texture.
     */
    SpriteComponent(GameObject& owner, TextureHandle texture);

    /**
     * @brief Constructor.
     * 
     * @param owner The owner of this component.
     */
    SpriteComponent(GameObject& owner);

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
     * @brief Destructor.
     */
    ~SpriteComponent() override;
};
