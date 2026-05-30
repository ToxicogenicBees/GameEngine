/*
    InputManager.cpp

    Implementation for the input system, which processes and relays user input events
*/

#include "Input/InputManager.hpp"
#include "Events/EventTypes/KeyEvent.hpp"
#include "Events/EngineEventDispatcher.hpp"
#include "Math/Vector2.hpp"
#include "Core/Services.hpp"
#include <SDL3/SDL.h>
#include <memory>

namespace {
    Vector2 windowToLogical(const Vector2& window) {
        SDL_FRect rect;
        SDL_GetRenderLogicalPresentationRect(Services::renderer()->raw(), &rect);

        auto logical = Services::renderer()->logicalSize();

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

void InputManager::startUpdate(double dt) {
    mouse_.refreshState();
    keys_.refreshState();
}

void InputManager::endUpdate(double dt) {
    for (auto& mouse : mouse_.allPressed())
        mouse_pressed_.fire(mouse, mouse_pos_);

    for (auto& mouse : mouse_.allReleased())
        mouse_released_.fire(mouse, mouse_pos_);

    for (auto& key : keys_.allPressed())
        key_pressed_.fire(key);

    for (auto& key : keys_.allReleased())
        key_released_.fire(key);
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

IBindableEvent<MouseButton, const Vector2&>& InputManager::onMouseReleased() {
    return mouse_released_;
}

IBindableEvent<MouseButton, const Vector2&>& InputManager::onMousePressed() {
    return mouse_pressed_;
}

IBindableEvent<KeyCode>& InputManager::onKeyReleased() {
    return key_released_;
}

IBindableEvent<KeyCode>& InputManager::onKeyPressed() {
    return key_pressed_;
}

InputManager::~InputManager() {
    for (auto& subscription : subscriptions_)
        EngineEventDispatcher::unsubscribe(subscription);
}
