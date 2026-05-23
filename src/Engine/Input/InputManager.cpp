/*
    InputManager.cpp

    Implementation for the input system, which processes and relays user input events
*/

#include "Input/InputManager.hpp"
#include "Events/EventTypes/MouseButtonEvent.hpp"
#include "Events/EventTypes/WindowCloseEvent.hpp"
#include "Events/EventTypes/MouseMotionEvent.hpp"
#include "Events/EventTypes/KeyEvent.hpp"
#include "Events/EngineEventQueue.hpp"
#include "Types/Vector2.hpp"
#include <SDL3/SDL.h>
#include <memory>

namespace {
    SDL_MouseButtonFlags getButtons() {
        return SDL_GetMouseState(nullptr, nullptr);
    }
}

bool InputManager::isMouseLeftDown() const {
    return (getButtons() & (SDL_MouseButtonFlags)MouseButton::LEFT);
}

bool InputManager::isMouseRightDown() const {
    return (getButtons() & (SDL_MouseButtonFlags)MouseButton::RIGHT);
}

bool InputManager::isMouseMiddleDown() const {
    return (getButtons() & (SDL_MouseButtonFlags)MouseButton::MIDDLE);
}

bool InputManager::isKeyDown(KeyCode key) const {
    // @TODO: Implement key checking
    return false;
}

Vector2i InputManager::mousePosition() const {
    float x, y;
    auto buttons = SDL_GetMouseState(&x, &y);
    return Vector2i{(int)x, (int)y};
}

void InputManager::poll() {
    SDL_Event event;

    // Create and push events
    while (SDL_PollEvent(&event)) {
        // Mouse pressed
        if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
            if (event.button.button == SDL_BUTTON_LEFT)
                EngineEventQueue::push(std::make_unique<MouseButtonEvent>(MouseButton::LEFT, true));
            else if (event.button.button == SDL_BUTTON_RIGHT)
                EngineEventQueue::push(std::make_unique<MouseButtonEvent>(MouseButton::RIGHT, true));
            else if (event.button.button == SDL_BUTTON_MIDDLE)
                EngineEventQueue::push(std::make_unique<MouseButtonEvent>(MouseButton::MIDDLE, true));
        }

        // Mouse moved
        if (event.type == SDL_EVENT_MOUSE_MOTION)
            EngineEventQueue::push(std::make_unique<MouseMotionEvent>(mousePosition()));
        
        // Quit
        if (event.type == SDL_EVENT_QUIT)
            EngineEventQueue::push(std::make_unique<WindowCloseEvent>());
    }
}
