/*
    InputManager.hpp

    Declaration for the input system, which processes and relays user input events
*/

#pragma once

#include "Events/BindableEvent.hpp"
#include "Events/EventTypes/MouseButtonEvent.hpp"
#include "Events/EventTypes/MouseMotionEvent.hpp"
#include "Events/EventSubscription.hpp"
#include "Input/InputBuffer.hpp"
#include "Math/Vector2.hpp"
#include <vector>

enum class MouseButton;
enum class KeyCode;

class InputManager {
private:
    std::vector<std::unique_ptr<EventSubscription>> subscriptions_;
    InputBuffer<MouseButton> mouse_;
    InputBuffer<KeyCode> keys_;
    Vector2 mouse_pos_;

    BindableEvent<MouseButton, const Vector2&> mouse_released_;
    BindableEvent<MouseButton, const Vector2&> mouse_pressed_;
    BindableEvent<KeyCode> key_released_;
    BindableEvent<KeyCode> key_pressed_;

public:
    /**
     * @brief Constructor
     */
    InputManager();

    /**
     * @brief Run logic to reset state at the beginning of a frame
     */
    void startUpdate();

    /**
     * @brief Run logic to finalize state at the end of a frame
     */
    void endUpdate();

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

    IBindableEvent<MouseButton, const Vector2&>& onMouseReleased();
    IBindableEvent<MouseButton, const Vector2&>& onMousePressed();
    IBindableEvent<KeyCode>& onKeyReleased();
    IBindableEvent<KeyCode>& onKeyPressed();

    /**
     * @brief Destructor.
     */
    ~InputManager();
};
