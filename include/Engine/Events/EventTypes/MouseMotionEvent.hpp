/*
    MouseMotionEvent.hpp

    Event for processing mouse movements
*/

#pragma once

#include "Events/EngineEvent.hpp"
#include "Math/Vector2.hpp"

struct MouseMotionEvent : public EngineEvent {
    Vector2i position;

    /**
     * @brief Constructor
     * 
     * @param position The position the mouse moved to on screen
     */
    MouseMotionEvent(const Vector2i& position)
        : position(position) {}
};
