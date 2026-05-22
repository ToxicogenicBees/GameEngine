/*
    Sprite.hpp

    Declaration for a 2D game object with a texture and position
*/

#pragma once

#include "Game/GameObjects/GameObject.hpp"

class Sprite : public GameObject {
public:
    std::shared_ptr<Texture> texture = nullptr;

    /**
     * @brief Initialization function ran once the object enters the game scene.
     */
    void init() override;

    /**
     * @brief Update function ran once every game tick.
     * 
     * @param dt Time difference, in seconds, since last update.
     */
    void update(double dt) override;

    /**
     * @brief Logic to handle removing the object from a scene.
     */
    void onDestroy() override;

    /**
     * @brief Logic to draw the object to a window
     * 
     * @param window The window the object is being drawn to
     */
    void render(Window& window) override;

    /**
     * @brief Gets the size of the game object.
     * 
     * @return The size of the game object.
     */
    Size size() const noexcept;

    /** 
     * @brief Gets the width of the game object.
     * 
     * @return The width of the game object.
     */
    size_t width() const noexcept;

    /**
     * @brief Gets the height of the game object.
     * 
     * @return The height of the game object.
     */
    size_t height() const noexcept;
};
