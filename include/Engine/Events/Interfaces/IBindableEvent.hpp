/*
    IBindableEvent.hpp

    An interface for a bindable event that allows other actors to connect to events.
*/

#pragma once

#include "Events/ScriptConnection.hpp"

template<typename... Args>
struct IBindableEvent {
    using Func = std::function<void(Args...)>;

    /**
     * @brief Connect to the bindable event.
     * 
     * @return A connection to the event.
     */
    virtual ScriptConnection connect(Func fn, int priority = 0) = 0;

    /**
     * @brief Destructor.
     */
    virtual ~IBindableEvent() = default;
};
