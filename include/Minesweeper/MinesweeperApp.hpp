/*
    MinesweeperApp.hpp

    Declaration for an application that implements minesweeper
*/

#pragma once

#include <Core/Application.hpp>

class MinesweeperApp final : public Application {
protected:
    /**
     * @brief Initializes the game
     */
    void init() override;

    /**
     * @brief Shuts down the game
     */
    void shutdown() override;

public:
    /**
     * @brief Constructor
     */
    MinesweeperApp();
};
