/*
    Sprite.hpp

    Declaration of a 2D sprite class
*/

#pragma once

#include "Rendering/Renderable.hpp"
#include "Resources/Textures/Texture.hpp"
#include "Geometry/Size.hpp"
#include "Math/Vector2.hpp"
#include <memory>

class Sprite : public Renderable {
private:
    std::shared_ptr<Texture> texture_ = nullptr;
    Vector2i offset_ = Vector2i::zero();
    Size size_ = Size{0, 0};

public:
    /**
     * @brief Constructor.
     * 
     * @param texture The desired texture.
     * @param offset The offset from the top-left of the texture.
     * @param size The size of the sprite.
     */
    Sprite(std::shared_ptr<Texture> texture, const Vector2i& offset, const Size& size);

    /**
     * @brief Constructor.
     * 
     * @param texture The desired texture.
     */
    Sprite(std::shared_ptr<Texture> texture);

    /**
     * @brief Constructor.
     */
    Sprite() = default;

    /**
     * @brief Get the texture of this sprite.
     * 
     * @return The texture of this sprite.
     */
    std::shared_ptr<Texture> texture() const;

    /**
     * @brief Get the texture of this sprite.
     * 
     * @return The texture of this sprite.
     */
    void setTexture(std::shared_ptr<Texture> texture, const Vector2i& offset, const Size& size);

    /**
     * @brief Get the texture of this sprite.
     * 
     * @return The texture of this sprite.
     */
    template<typename string_t>
    void setTexture(const string_t& texture, const Vector2i& offset, const Size& size);
    
    /**
     * @brief Get the texture of this sprite.
     * 
     * @return The texture of this sprite.
     */
    void setTexture(std::shared_ptr<Texture> texture);
    
    /**
     * @brief Get the texture of this sprite.
     * 
     * @return The texture of this sprite.
     */
    template<typename string_t>
    void setTexture(const string_t& texture);

    /**
     * @brief Get the position of this sprite.
     * 
     * @return The position of this sprite.
     */
    Vector2i offset() const;

    /**
     * @brief Get the size of this sprite.
     * 
     * @return The size of this sprite.
     */
    Size size() const;
};
