/*
    GameScene.hpp

    Declaration for a minesweeper game scene
*/

#pragma once

#include "Minesweeper/Boards/RandomBoard.hpp"
#include <Scene/Scene.hpp>
#include <memory>
#include <array>

class GameScene final : public Scene {
private:
    // Textures
    std::array<std::shared_ptr<Texture>, 9> numbers_;
    std::shared_ptr<Texture> hidden_;
    std::shared_ptr<Texture> flag_;
    std::shared_ptr<Texture> mine_;

    RandomBoard board_;

    std::shared_ptr<Texture> resolveTileTexture_(const Tile& tile);

    /**
     * @brief Logic for a left click
     */
    void onLeftClick_();

    /**
     * @brief Logic for a right click
     */
    void onRightClick_();

protected:
    /**
     * @brief Customizable initialization behavior
     */
    void onInit() override;

    /**
     * @brief Customizable update behavior
     * 
     * @param dt The time difference since the last update
     */
    void onUpdate(double dt) override;

    /**
     * @brief Customizable render behavior
     */
    void onRender() override;

    /**
     * @brief Customizable unload behavior
     */
    void onUnload() override;

public:
    /**
     * @brief Constructor
     */
    GameScene();
};
