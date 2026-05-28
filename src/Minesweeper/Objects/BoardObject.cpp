/*
    BoardObject.cpp

    Implementation for a minesweeper board
*/

#include "Minesweeper/Objects/BoardObject.hpp"

BoardObject::BoardObject()
    : sprite_(addComponent<SpriteComponent>("board.png")) {}
