/*
    InputManager.hpp

    Declaration for the input system, which processes and relays user input events
*/

#pragma once

#include "Core/System/Subsystem.hpp"
#include "Core/Interfaces/IFrameLifecycle.hpp"
#include "Core/System/Macrosystem.hpp"
#include "Events/BindableEvent.hpp"
#include "Events/EventTypes/MouseButtonEvent.hpp"
#include "Events/EventTypes/KeyButtonEvent.hpp"
#include "Events/EventSubscription.hpp"
#include "Rendering/Renderer.hpp"
#include "Input/InputBuffer.hpp"
#include "Math/Vector2.hpp"
#include <vector>
#include <memory>

class InputManager final : public Subsystem, public IFrameLifecycle {
private:
    std::vector<std::unique_ptr<EventSubscription>> subscriptions_;
    InputBuffer<MouseButton> mouse_;
    InputBuffer<KeyCode> keys_;
    Vector2 mouse_pos_;

    BindableEvent<MouseButton, Vector2> mouse_released_;
    BindableEvent<MouseButton, Vector2> mouse_pressed_;
    BindableEvent<KeyCode> key_released_;
    BindableEvent<KeyCode> key_pressed_;

    Renderer* renderer_ = nullptr;

public:
    /**
     * @brief Constructor
     */
    InputManager();

    /**
     * @brief Depencency resolution logic.
     * 
     * @param system The macrosystem this system is owned by.
     */
    void resolveDependencies(Macrosystem* system) final;

    /**
     * @brief Run logic to reset state at the beginning of a frame
     */
    void beginFrame() final;

    /**
     * @brief Run logic to finalize state at the end of a frame
     */
    void endFrame() final;

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
     * @brief Gets a bindable event fired every mouse release.
     * 
     * @return Bindable event fired every mouse release.
     */
    IBindableEvent<MouseButton, Vector2>& onMouseReleased();

    /**
     * @brief Gets a bindable event fired every mouse press.
     * 
     * @return Bindable event fired every mouse press.
     */
    IBindableEvent<MouseButton, Vector2>& onMousePressed();

    /**
     * @brief Gets a bindable event fired every key release.
     * 
     * @return Bindable event fired every key release.
     */
    IBindableEvent<KeyCode>& onKeyReleased();

    /**
     * @brief Gets a bindable event fired every key press.
     * 
     * @return Bindable event fired every key press.
     */
    IBindableEvent<KeyCode>& onKeyPressed();

    /**
     * @brief Destructor.
     */
    ~InputManager();
};
