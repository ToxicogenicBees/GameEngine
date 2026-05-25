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

namespace {
    Vector2 windowToLogical(const Vector2& window) {
        SDL_FRect rect;
        SDL_GetRenderLogicalPresentationRect(Services::renderer()->raw(), &rect);

        Size logical = Services::renderer()->logicalSize();

        return {
            (window.x - rect.x) * logical.width() / rect.w,
            (window.y - rect.y) * logical.height() / rect.h
        };
    }
}

InputManager::InputManager() {
    EngineEventDispatcher::subscribe<MouseButtonEvent>([this](const MouseButtonEvent& event) {
        mouse_pos_ = windowToLogical(event.position);
        if (event.pressed)
            mouse_.registerPress(event.button);
        else
            mouse_.registerRelease(event.button);
    });

    EngineEventDispatcher::subscribe<MouseMotionEvent>([this](const MouseMotionEvent& event) {
        mouse_pos_ = windowToLogical(event.position);
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

Vector2 InputManager::mousePosition() const {
    return mouse_pos_;
}

InputManager::~InputManager() {
    for (auto& subscription : subscriptions_)
        EngineEventDispatcher::unsubscribe(subscription);
}
