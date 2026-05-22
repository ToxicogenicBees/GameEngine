/*
    InputSystem.hpp

    Declaration for the input system, which processes and relays user input events
*/

#pragma once

#include "Communication/Events/MouseButtonEvent.hpp"
#include "Communication/Events/KeyEvent.hpp"

class InputSystem {
private:
    /**
     * @brief Constructor (deleted)
     */
    InputSystem() = delete;

public:
    /**
     * @brief Gets if a specific mouse button is pressed.
     * 
     * @param button The mouse button being checked.
     * @return True if the button is pressed, and false otherwise.
     */
    static bool isMouseDown(MouseButton button);

    /**
     * @brief Gets if a specific mouse button is pressed.
     * 
     * @param key The key being checked.
     * @return True if the key is pressed, and false otherwise.
     */
    static bool isKeyDown(KeyCode key);

    /**
     * @brief Gets the location of the mouse on screen.
     * 
     * @return The location of the mouse on screen.
     */
    static Vector2i mousePosition();

    /**
     * @brief Polls user input and sends the proper events to the event queue
     */
    static void poll();
};
