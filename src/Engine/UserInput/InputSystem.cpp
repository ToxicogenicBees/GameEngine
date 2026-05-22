/*
    InputSystem.cpp

    Implementation for the input system, which processes and relays user input events
*/

#include "UserInput/InputSystem.hpp"
#include "Communication/Events/MouseButtonEvent.hpp"
#include "Communication/Events/WindowCloseEvent.hpp"
#include "Communication/Events/MouseMovedEvent.hpp"
#include "Communication/Events/KeyEvent.hpp"
#include "Communication/EngineEventQueue.hpp"
#include "Types/Vector2.hpp"
#include <SDL3/SDL.h>
#include <memory>

/**
 * @brief Gets if a specific mouse button is pressed.
 * 
 * @param button The mouse button being checked.
 * @return True if the button is pressed, and false otherwise.
 */
bool InputSystem::isMouseDown(MouseButton button) {
    SDL_MouseButtonFlags buttons = SDL_GetMouseState(nullptr, nullptr);

    return (buttons & (SDL_MouseButtonFlags)button);
}

/**
 * @brief Gets if a specific mouse button is pressed.
 * 
 * @param key The key being checked.
 * @return True if the key is pressed, and false otherwise.
 */
bool InputSystem::isKeyDown(KeyCode key) {
    // TODO: Implement key checking
    return false;
}

/**
 * @brief Gets the location of the mouse on screen.
 * 
 * @return The location of the mouse on screen.
 */
Vector2i InputSystem::mousePosition() {
    float x, y;
    auto buttons = SDL_GetMouseState(&x, &y);
    return Vector2i{(int)x, (int)y};
}

/**
 * @brief Polls user input and sends the proper events to the event queue
 */
void InputSystem::poll() {
    SDL_Event event;

    // Create and push events
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
            if (event.button.button == SDL_BUTTON_LEFT)
                EngineEventQueue::push(std::make_unique<MouseButtonEvent>(MouseButton::LEFT, true));
            if (event.button.button == SDL_BUTTON_RIGHT)
                EngineEventQueue::push(std::make_unique<MouseButtonEvent>(MouseButton::RIGHT, true));
            if (event.button.button == SDL_BUTTON_MIDDLE)
                EngineEventQueue::push(std::make_unique<MouseButtonEvent>(MouseButton::MIDDLE, true));
        }
            
        if (event.type == SDL_EVENT_QUIT)
            EngineEventQueue::push(std::make_unique<WindowCloseEvent>());
    }
}
