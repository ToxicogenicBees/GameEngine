/*
    MouseClickEvent.hpp

    Event for processing mouse presses
*/

#pragma once

#include "Events/EngineEvent.hpp"
#include "Math/Vector2.hpp"
#include <SDL3/SDL.h>

enum class MouseButton {
    LEFT = SDL_BUTTON_LEFT,
    RIGHT = SDL_BUTTON_RIGHT,
    MIDDLE = SDL_BUTTON_MIDDLE
};

struct MouseButtonEvent : public EngineEvent {
    MouseButton button;
    bool pressed;
    Vector2i position;

    /**
     * @brief Constructor
     * 
     * @param button The mouse button this action is about
     * @param pressed If the mouse button is pressed or not
     * @param position The mouse position of the click
     */
    MouseButtonEvent(MouseButton button, bool pressed, Vector2i position)
        : button(button), pressed(pressed), position(position) {}
};
