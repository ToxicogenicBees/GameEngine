/*
    GameScene.hpp

    Declaration for a minesweeper game scene
*/

#pragma once

#include <Scene/Scene.hpp>
#include "Minesweeper/Objects/Boards/RandomBoard.hpp"
#include "Minesweeper/Objects/SmileButton.hpp"
#include <Types/Size.hpp>
#include <memory>
#include <array>

class EasyBoard final : public Scene {
private:
    RandomBoard* board_;
    SmileButton* smile_;

    /**
     * @brief Logic for a left click
     * 
     * @param mouse_pos The position of the mouse
     */
    void onLeftClick_(const Vector2i& mouse_pos);

    /**
     * @brief Logic for a right click
     * 
     * @param mouse_pos The position of the mouse
     */
    void onRightClick_(const Vector2i& mouse_pos);

protected:
    /**
     * @brief Customizable initialization behavior
     */
    void onInit() override;

    /**
     * @brief Custom update logic
     * 
     * @param dt Time between updates
     */
    void onUpdate(double dt) override;

public:
    /**
     * @brief Constructor
     */
    EasyBoard();
};
