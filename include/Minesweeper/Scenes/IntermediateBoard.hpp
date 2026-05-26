/*
    IntermediateBoard.hpp

    Declaration for a minesweeper game scene
*/

#pragma once

#include <Scene/Scene.hpp>
#include "Minesweeper/Objects/Boards/RandomBoard.hpp"
#include "Minesweeper/Objects/SmileButton.hpp"
#include "Minesweeper/Objects/Counter.hpp"
#include <Types/Size.hpp>
#include <memory>
#include <array>

class IntermediateBoard final : public Scene {
private:
    std::array<Counter*, 3> counter_{nullptr};
    std::array<Counter*, 3> timer_{nullptr};
    RandomBoard* board_;
    SmileButton* smile_;
    double elapsed_time_ = 0.0;

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

    /**
     * @brief Update the mine count display
     * 
     * @param count The new mine count
     */
    void setCount_(int count);

    /**
     * @brief Update the timer display
     * 
     * @param time The new timer value
     */
    void setTimer_(int time);

    /**
     * @brief Generate a new board.
     */
    void generate_();

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
    IntermediateBoard();
};
