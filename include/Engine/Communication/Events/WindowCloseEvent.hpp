/*
    WindowCloseEvent.hpp

    Event for processing mouse movements
*/

#pragma once

#include "Communication/Events/EngineEvent.hpp"

struct WindowCloseEvent : public EngineEvent {
    /**
     * @brief Constructor
     */
    WindowCloseEvent() = default;
};
