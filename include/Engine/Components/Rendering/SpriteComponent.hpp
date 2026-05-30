/*
    SpriteComponent.hpp

    Declaration for a component containing a 2D sprite
*/

#pragma once

#include "Components/Component.hpp"
#include "Resources/Textures/Texture.hpp"
#include "Types/DimVector.hpp"
#include <string>
#include <memory>

class SpriteComponent final : public Component {
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
     * @brief Constructor.
     * 
     * @param texture The desired texture.
     */
    SpriteComponent(std::shared_ptr<Texture> texture);

    /**
     * @brief Constructor.
     * 
     * @param texture The desired texture.
     */
    template<typename string_t>
    SpriteComponent(const string_t& texture);

    /**
     * @brief Constructor.
     */
    SpriteComponent() = default;

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
    template<typename string_t>
    void setTexture(const string_t& texture);

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
};

#include "Components/Rendering/SpriteComponent.tpp"
