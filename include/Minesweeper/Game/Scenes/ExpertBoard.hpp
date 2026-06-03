/*
    ExpertBoard.hpp

    Declaration for an expert minesweeper game scene
*/

#pragma once

#include "Minesweeper/Game/Scenes/TileableBoard.hpp"

class ExpertBoard final : public TileableBoard {
public:
    /**
     * @brief Constructor.
     * 
     * @param context The engine context for this scene.
     */
    ExpertBoard(EngineContext& context);
};
