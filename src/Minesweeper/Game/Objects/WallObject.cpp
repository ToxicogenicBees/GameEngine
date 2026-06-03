/*
    WallObject.cpp

    Implementation for a minesweeper wall
*/

#include "Minesweeper/Game/Objects/WallObject.hpp"

WallObject::WallObject(const Sprite& sprite)
    : sprite_(addComponent<SpriteComponent>(sprite))
{
    sprite_->setLayer(0);
}
