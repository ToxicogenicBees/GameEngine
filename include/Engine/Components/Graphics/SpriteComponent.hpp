/*
    SpriteComponent.hpp

    Declaration for a component containing a 2D sprite
*/

#pragma once

#include "Components/Component.hpp"
#include "Rendering/Renderable.hpp"
#include "Graphics/Sprites/Sprite.hpp"
#include "Math/Vector2.hpp"
#include <string>

class SpriteComponent final : public Component, public Renderable {
private:
    Vector2 anchor_ = Vector2::zero();
    Sprite sprite_;

protected:
    /**
     * @brief Custom render logic.
     */
    void onRender() override;

    /**
     * @brief Custom initialization logic.
     */
    void onInit() override;

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
     * @brief Gets the sprite of this component.
     * 
     * @return The texture.
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

    /**
     * @brief Destructor.
     */
    ~SpriteComponent();
};
