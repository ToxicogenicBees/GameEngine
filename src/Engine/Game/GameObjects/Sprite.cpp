/*
    Sprite.cpp

    Implementation for a 2D game object with a texture and position
*/

#include "Game/GameObjects/Sprite.hpp"

/**
 * @brief Initialization function ran once the object enters the game scene.
 */
void Sprite::init() {

}

/**
 * @brief Update function ran once every game tick.
 * 
 * @param dt Time difference, in seconds, since last update.
 */
void Sprite::update(double dt) {

}

/**
 * @brief Logic to handle removing the object from a scene.
 */
void Sprite::onDestroy() {

}

/**
 * @brief Logic to draw the object to a window
 * 
 * @param window The window the object is being drawn to
 */
void Sprite::render(Window& window) {
    window.drawTexture(texture, position);
}

/**
 * @brief Gets the size of the game object.
 * 
 * @return The size of the game object.
 */
Size Sprite::size() const noexcept {
    return texture->size();
}

/** 
 * @brief Gets the width of the game object.
 * 
 * @return The width of the game object.
 */
size_t Sprite::width() const noexcept {
    return texture->width();
}

/**
 * @brief Gets the height of the game object.
 * 
 * @return The height of the game object.
 */
size_t Sprite::height() const noexcept {
    return texture->height();
}
