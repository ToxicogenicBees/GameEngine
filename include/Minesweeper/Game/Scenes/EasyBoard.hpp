/*
    EasyBoard.hpp

    Declaration for an easy minesweeper game scene
*/

#pragma once

#include "Minesweeper/Game/Scenes/TileableBoard.hpp"

class EasyBoard final : public TileableBoard {
public:
    /**
     * @brief Constructor.
     * 
     * @param context The engine context for this scene.
     */
    EasyBoard(EngineContext& context);
};
