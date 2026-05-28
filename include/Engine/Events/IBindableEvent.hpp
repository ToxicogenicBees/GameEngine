/*
    IBindableEvent.hpp

    An interface for a bindable event that allows other actors to connect to events.
*/

#pragma once

#include "Events/ScriptConnection.hpp"
#include <memory>

template<typename... Args>
struct IBindableEvent {
    /**
     * @brief Connect to the bindable event.
     * 
     * @return A connection to the event.
     */
    virtual std::shared_ptr<ScriptConnection> connect(std::function<void(Args...)> listener) = 0;

    /**
     * @brief Destructor.
     */
    virtual ~IBindableEvent() = default;
};
