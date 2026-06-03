/*
    IntermediateBoard.cpp

    Implementation for an intermediate minesweeper game scene
*/

#include "Minesweeper/Game/Scenes/IntermediateBoard.hpp"

IntermediateBoard::IntermediateBoard(EngineContext& context)
    : TileableBoard(context, Size{16, 16}, 40) {}
