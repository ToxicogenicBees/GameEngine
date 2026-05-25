/*
    InputManager.hpp

    Declaration for the input system, which processes and relays user input events
*/

#pragma once

#include "Events/EventTypes/MouseButtonEvent.hpp"
#include "Events/EventTypes/KeyEvent.hpp"
#include "Events/EventSubscription.hpp"
#include "Input/InputBuffer.hpp"
#include <vector>

class InputManager {
private:
    std::vector<EventSubscription> subscriptions_;
    InputBuffer<MouseButton> mouse_;
    InputBuffer<KeyCode> keys_;
    Vector2 mouse_pos_;

public:
    /**
     * @brief Constructor
     */
    InputManager();

    /**
     * @brief Refresh state and await dispatched events
     */
    void refreshState();

    /**
     * @brief Gets if a specific mouse button was pressed.
     * 
     * @param button The mouse button being checked
     * 
     * @return True if the button was pressed, and false otherwise.
     */
    bool wasPressed(MouseButton button) const;

    /**
     * @brief Gets if a specific keyboard button was pressed.
     * 
     * @param button The keyboard button being checked
     * 
     * @return True if the button was pressed, and false otherwise.
     */
    bool wasPressed(KeyCode button) const;

    /**
     * @brief Gets if a specific mouse button was released.
     * 
     * @param button The mouse button being checked
     * 
     * @return True if the button was released, and false otherwise.
     */
    bool wasReleased(MouseButton button) const;

    /**
     * @brief Gets if a specific keyboard button was released.
     * 
     * @param button The keyboard button being checked
     * 
     * @return True if the button was released, and false otherwise.
     */
    bool wasReleased(KeyCode button) const;

    /**
     * @brief Gets if a specific mouse button is held.
     * 
     * @param button The mouse button being checked
     * 
     * @return True if the button is held, and false otherwise.
     */
    bool isHeld(MouseButton button) const;

    /**
     * @brief Gets if a specific keyboard button is held.
     * 
     * @param button The keyboard button being checked
     * 
     * @return True if the button is held, and false otherwise.
     */
    bool isHeld(KeyCode button) const;

    /**
     * @brief Gets the location of the mouse on screen.
     * 
     * @return The location of the mouse on screen.
     */
    Vector2 mousePosition() const;

    /**
     * @brief Destructor.
     */
    ~InputManager();
};
