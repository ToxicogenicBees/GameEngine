/*
    WallObject.cpp

    Implementation for a minesweeper wall
*/

#include "Minesweeper/Game/Objects/WallObject.hpp"

WallObject::WallObject(Scene& scene, const Sprite& sprite)
    : GameObject(scene),
      sprite_(addComponent<SpriteComponent>(sprite))
{
    sprite_->setLayer(0);
}
