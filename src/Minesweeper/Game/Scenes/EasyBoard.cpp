/*
    EasyBoard.cpp

    Implementation for an easy minesweeper game scene
*/

#include "Minesweeper/Game/Scenes/EasyBoard.hpp"

EasyBoard::EasyBoard(EngineContext& context)
    : TileableBoard(context, Size{9, 9}, 10) {}
