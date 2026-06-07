/*
    WallObject.cpp

    Implementation for a minesweeper wall
*/

#include "Minesweeper/Game/Objects/WallObject.hpp"

WallObject::WallObject(Scene& scene, std::shared_ptr<Texture> texture)
    : GameObject(scene),
      sprite_(addComponent<SpriteComponent>(texture))
{
    sprite_->setLayer(0);
}
