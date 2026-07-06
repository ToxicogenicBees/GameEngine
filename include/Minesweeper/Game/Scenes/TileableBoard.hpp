/*
    TileableBoard.hpp

    Declaration for a minesweeper board scene that is composed of tileable objects, allowing for arbitrary board sizes.
*/

#pragma once

#include <World/Scene.hpp>
#include <Events/Listeners/UpdateListener.hpp>
#include "Minesweeper/Game/Objects/SmileButton.hpp"
#include "Minesweeper/Game/Objects/TileObject.hpp"
#include "Minesweeper/Game/Objects/WallObject.hpp"
#include "Minesweeper/Game/Objects/Counter.hpp"
#include "Minesweeper/Core/Board.hpp"
#include <vector>
#include <array>

class TileableBoard : public Scene, public UpdateListener {
private:
    // Constants
    const size_t MINE_COUNT_;
    const Size BOARD_SIZE_;
    const Size WALL_SIZE_;

    // Input connections
    std::vector<ScriptConnection> connections_;

    // Counters
    std::array<Counter*, 3> counter_{nullptr};
    std::array<Counter*, 3> timer_{nullptr};
    double elapsed_time_ = 0.0;

    // Tiles
    std::vector<TileObject*> tiles_;
    std::vector<WallObject*> walls_;

    // Smile button
    SmileButton* smile_;

    // Board
    Board board_;

    /**
     * @brief Gets the tile at the specified screen position.
     * 
     * @param screen_pos The specified screen position.
     */
    TileObject* tileAt_(Vector2 screen_pos);

    /**
     * @brief Logic for a left click
     * 
     * @param mouse_pos The position of the mouse
     */
    void onLeftClick_(Vector2i mouse_pos);

    /**
     * @brief Logic for a right click
     * 
     * @param mouse_pos The position of the mouse
     */
    void onRightClick_(Vector2i mouse_pos);

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

    /**
     * @brief Generates the walls of the board.
     */
    void generateWalls_();

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
     * @brief Constructor.
     * 
     * @param size The size of the board.
     * @param mine_count The number of mines on the board.
     */
    TileableBoard(Size size, size_t mine_count);
};
