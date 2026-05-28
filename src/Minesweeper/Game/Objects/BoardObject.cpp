/*
    BoardObject.cpp

    Implementation for a minesweeper board
*/

#include "Minesweeper/Game/Objects/BoardObject.hpp"

BoardObject::BoardObject()
    : sprite_(addComponent<SpriteComponent>("board.png")) {}
