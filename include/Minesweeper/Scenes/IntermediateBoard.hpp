/*
    IntermediateBoard.hpp

    Declaration for a minesweeper game scene
*/

#pragma once

#include <Scene/Scene.hpp>
#include "Minesweeper/Objects/BoardObject.hpp"
#include "Minesweeper/Objects/SmileButton.hpp"
#include "Minesweeper/Objects/TileObject.hpp"
#include "Minesweeper/Objects/Counter.hpp"
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
     * @brief Gets the tile at the given mouse position.
     * 
     * @param mouse_pos The desired mouse position
     */
    TileObject* tileAt_(const Vector2& mouse_pos);

    /**
     * @brief Gets the tile at the given tile index.
     * 
     * @param index The desired tile index.
     */
    TileObject* tileWithIndex_(const Vector2i& index);

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
     * @brief Generates a new board.
     */
    void generateBoard_();

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
