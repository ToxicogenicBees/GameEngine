/*
    BindableEvent.hpp

    Declaration for a message communication scheme
*/

#pragma once

#include "Events/Interfaces/IBindableEvent.hpp"
#include "Events/ScriptConnection.hpp"
#include "Utility/Guid.hpp"
#include <unordered_map>
#include <functional>
#include <memory>
#include <mutex>

template<typename... Args>
class BindableEvent : public IBindableEvent<Args...> {
private:
    struct Entry {
        int priority;
        Guid id;
        IBindableEvent<Args...>::Func fn;
    };

    std::vector<Entry> entries_;

public:
    /**
     * @brief Connect to the bindable event.
     * 
     * @return A connection to the event.
     */
    ScriptConnection connect(IBindableEvent<Args...>::Func fn, int priority = 0) override;

    /**
     * @brief Fires the event and runs the corresponding event handlers.
     */
    void fire(Args... args);
};

#include "Events/BindableEvent.tpp"
