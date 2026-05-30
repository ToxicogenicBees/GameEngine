/*
    BoardObject.hpp

    Declaration for a minesweeper board
*/

#pragma once

#include <World/GameObject.hpp>
#include <Components/Rendering/SpriteComponent.hpp>

class BoardObject : public GameObject {
private:
    SpriteComponent* sprite_;

public:
    /**
     * @brief Constructor
     */
    BoardObject();
};
