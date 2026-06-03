/*
    ExpertBoard.cpp

    Implementation for an expert minesweeper game scene
*/

#include "Minesweeper/Game/Scenes/ExpertBoard.hpp"

ExpertBoard::ExpertBoard(EngineContext& context)
    : TileableBoard(context, Size{30, 16}, 99) {}
