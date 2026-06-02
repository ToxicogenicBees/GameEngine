/*
    BoardObject.cpp

    Implementation for a minesweeper board
*/

#include "Minesweeper/Game/Objects/BoardObject.hpp"
#include <Core/Services.hpp>

BoardObject::BoardObject()
    : sprite_(addComponent<SpriteComponent>()) 
{
    auto texture = Services::resources()->loadTexture("board.png");
    auto sprite = Sprite(texture);
    sprite_->setSprite(sprite);
}
