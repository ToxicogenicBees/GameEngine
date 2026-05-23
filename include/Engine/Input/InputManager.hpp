/*
    InputManager.hpp

    Declaration for the input system, which processes and relays user input events
*/

#pragma once

#include "Events/EventTypes/MouseButtonEvent.hpp"
#include "Events/EventTypes/KeyEvent.hpp"

class InputManager {
public:
    /**
     * @brief Constructor
     */
    InputManager() = default;

    /**
     * @brief Gets if a specific mouse button is pressed.
     * 
     * @return True if the button is pressed, and false otherwise.
     */
    bool isMouseLeftDown() const;

    /**
     * @brief Gets if the left mouse button is pressed.
     * 
     * @return True if the button is pressed, and false otherwise.
     */
    bool isMouseRightDown() const;

    /**
     * @brief Gets if the right mouse button is pressed.
     * 
     * @return True if the button is pressed, and false otherwise.
     */
    bool isMouseMiddleDown() const;

    /**
     * @brief Gets if the middle mouse button is pressed.
     * 
     * @param key The key being checked.
     * @return True if the key is pressed, and false otherwise.
     */
    bool isKeyDown(KeyCode key) const;

    /**
     * @brief Gets the location of the mouse on screen.
     * 
     * @return The location of the mouse on screen.
     */
    Vector2i mousePosition() const;

    /**
     * @brief Polls user input and sends the proper events to the event queue
     */
    void poll();
};
