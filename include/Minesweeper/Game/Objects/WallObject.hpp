/*
    WallObject.hpp

    Declaration for a minesweeper wall
*/

#pragma once

#include <World/GameObject.hpp>
#include <Components/Graphics/SpriteComponent.hpp>
#include <Graphics/Sprites/Sprite.hpp>
#include <memory>
#include <stdint.h>

class WallObject : public GameObject {
private:
    SpriteComponent* sprite_;

public:
    /**
     * @brief Constructor.
     * 
     * @param scene The scene that owns this object.
     * @param sprite The sprite for this wall.
     */
    WallObject(Scene& scene, const Sprite& sprite);
};
