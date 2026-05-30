/*
    BoardObject.hpp

    Declaration for a minesweeper board
*/

#pragma once

#include <Core/GameObject.hpp>
#include <Components/SpriteComponent.hpp>

class BoardObject : public GameObject {
private:
    SpriteComponent* sprite_;

public:
    /**
     * @brief Constructor
     */
    BoardObject();
};
