/*
    InputManager.cpp

    Implementation for the input system, which processes and relays user input events
*/

#include "Input/InputManager.hpp"
#include "Events/EventTypes/MouseButtonEvent.hpp"
#include "Events/EventTypes/MouseMotionEvent.hpp"
#include "Events/EventTypes/KeyEvent.hpp"
#include "Events/EngineEventDispatcher.hpp"
#include "Types/Vector2.hpp"
#include "Core/Services.hpp"
#include <SDL3/SDL.h>
#include <memory>

InputManager::InputManager() {
    EngineEventDispatcher::subscribe<MouseButtonEvent>([this](const MouseButtonEvent& event) {
        mouse_pos_ = event.position;
        if (event.pressed)
            mouse_.registerPress(event.button);
        else
            mouse_.registerRelease(event.button);
    });

    EngineEventDispatcher::subscribe<MouseMotionEvent>([this](const MouseMotionEvent& event) {
        mouse_pos_ = event.position;
    });
}

void InputManager::refreshState() {
    mouse_.refreshState();
    keys_.refreshState();
}

bool InputManager::wasPressed(MouseButton button) const {
    return mouse_.wasPressed(button);
}

bool InputManager::wasPressed(KeyCode button) const {
    return keys_.wasPressed(button);
}

bool InputManager::wasReleased(MouseButton button) const {
    return mouse_.wasReleased(button);
}

bool InputManager::wasReleased(KeyCode button) const {
    return keys_.wasReleased(button);
}

bool InputManager::isHeld(MouseButton button) const {
    return mouse_.isHeld(button);
}

bool InputManager::isHeld(KeyCode button) const {
    return keys_.isHeld(button);
}

Vector2i InputManager::mousePosition() const {
    // SDL_FRect rect;
    // SDL_GetRenderLogicalPresentationRect(Services::renderer()->raw(), &rect);

    // Size logical = Services::renderer()->logicalSize();

    // return {
    //     (int)((mouse_pos_.x - rect.x) / rect.w * logical.width()),
    //     (int)((mouse_pos_.y - rect.y) / rect.h * logical.height())
    // };

    return mouse_pos_;
}

InputManager::~InputManager() {
    for (auto& subscription : subscriptions_)
        EngineEventDispatcher::unsubscribe(subscription);
}
