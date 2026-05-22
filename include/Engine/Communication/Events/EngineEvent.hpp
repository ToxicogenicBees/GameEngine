/*
    EngineEvent.hpp

    Declaration for an abstract event class, used for inter-script communication and event handling
*/

#pragma once

struct EngineEvent {
    /**
     * @brief Constructor
     */
    EngineEvent() = default;

    /**
     * @brief Destructor
     */
    virtual ~EngineEvent() = default;
};
