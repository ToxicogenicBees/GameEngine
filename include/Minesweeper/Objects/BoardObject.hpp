/*
    BoardObject.hpp

    Declaration for a minesweeper board
*/

#pragma once

#include <GameObject/GameObject.hpp>
#include <Components/SpriteComponent.hpp>
#include "Minesweeper/Objects/TileObject.hpp"
#include "Types/Size.hpp"
#include <functional>
#include <memory>
#include <vector>

enum class BoardState {
    PLAYING,
    WIN,
    LOSE
};

class BoardObject : public GameObject {
private:
    SpriteComponent* sprite_;

public:
    /**
     * @brief Constructor
     */
    BoardObject();
};
