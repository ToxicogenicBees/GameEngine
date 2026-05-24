/*
    SpriteComponent.hpp

    Declaration for a component containing a 2D sprite
*/

#pragma once

#include "GameObject/Component.hpp"
#include "Rendering/Texture.hpp"
#include "Types/DimVector.hpp"
#include <memory>

class SpriteComponent : public Component {
private:
    std::shared_ptr<Texture> texture_;
    DimVector offset_;

protected:
    /**
     * @brief Custom render logic
     * 
     * @param camera Reference to the rendering camera object
     */
    void onRender(Camera& camera) override;

public:
    /**
     * @brief Set the texture of this component.
     * 
     * @param texture The desired texture.
     */
    void setTexture(std::shared_ptr<Texture> texture);

    /**
     * @brief Set the texture of this component.
     * 
     * @param texture The desired texture.
     */
    std::shared_ptr<Texture> texture() const;

    /**
     * @brief Gets the sprite's offset.
     * 
     * @return A the sprite's offset.
     */
    DimVector offset() const;
    
    /**
     * @brief Sets the sprite's offset.
     * 
     * @param offset The desired offset.
     */
    void setOffset(const DimVector& offset);

    /**
     * @brief Gets the size of the texture.
     * 
     * @return The size of the texture.
     */
    Size size() const;

    /**
     * @brief Gets the width of the texture.
     * 
     * @return The width of the texture.
     */
    size_t width() const;

    /**
     * @brief Gets the height of the texture.
     * 
     * @return The height of the texture.
     */
    size_t height() const;
};
