/*
    WallObject.hpp

    Declaration for a minesweeper wall
*/

#pragma once

#include <World/GameObject.hpp>
#include <Components/Graphics/SpriteComponent.hpp>
#include <Resources/Types/Texture.hpp>
#include <memory>

class WallObject : public GameObject {
private:
    SpriteComponent* sprite_;

public:
    /**
     * @brief Constructor.
     * 
     * @param scene The scene that owns this object.
     * @param texture The texture for this wall's sprite.
     */
    WallObject(Scene& scene, TextureHandle texture);
};
