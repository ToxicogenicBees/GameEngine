/*
    MouseMovedEvent.hpp

    Event for processing mouse movements
*/

#pragma once

#include "Communication/Events/EngineEvent.hpp"
#include "Types/Vector2.hpp"

struct MouseClickEvent : public EngineEvent {
    Vector2i position;

    /**
     * @brief Constructor
     * 
     * @param position The position the mouse moved to on screen
     */
    MouseClickEvent(const Vector2i& position)
        : position(position) {}
};
