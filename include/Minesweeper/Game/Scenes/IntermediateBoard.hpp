/*
    IntermediateBoard.hpp

    Declaration for a minesweeper game scene
*/

#pragma once

#include <Scene/Scene.hpp>
#include "Minesweeper/Game/Objects/BoardObject.hpp"
#include "Minesweeper/Game/Objects/SmileButton.hpp"
#include "Minesweeper/Game/Objects/TileObject.hpp"
#include "Minesweeper/Game/Objects/Counter.hpp"
#include "Minesweeper/Core/Board.hpp"
#include <Types/Size.hpp>
#include <memory>
#include <array>

class IntermediateBoard final : public Scene {
private:
    // Counters
    std::array<Counter*, 3> counter_{nullptr};
    std::array<Counter*, 3> timer_{nullptr};
    double elapsed_time_ = 0.0;

    // Tiles
    std::vector<TileObject*> tiles_;

    // Board background
    BoardObject* background_;

    // Smile button
    SmileButton* smile_;

    // Minesweeper board
    Board board_;

    /**
     * @brief Gets the tile at the specified screen position.
     * 
     * @param screen_pos The specified screen position.
     */
    TileObject* tileAt_(const Vector2& screen_pos);

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
     */
    void updateMineCount_();

    /**
     * @brief Update the timer display
     * 
     * @param dt Time between updates
     */
    void updateTimer_(double time);

    /**
     * @brief Resets the timer display
     */
    void resetTimer_();

    /**
     * @brief Resets the board
     */
    void reset_();

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
