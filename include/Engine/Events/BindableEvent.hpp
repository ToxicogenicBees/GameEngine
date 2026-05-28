/*
    BindableEvent.hpp

    Declaration for a message communication scheme
*/

#pragma once

#include "Events/IBindableEvent.hpp"
#include "Events/ScriptConnection.hpp"
#include <unordered_map>
#include <functional>
#include <memory>
#include <mutex>

template<typename... Args>
class BindableEvent : public IBindableEvent<Args...> {
private:
    using Listener = std::function<void(Args...)>;

    std::unordered_map<size_t, std::shared_ptr<ScriptConnection>> connections_;
    std::unordered_map<size_t, Listener> listeners_;
    std::mutex mutex_;
    size_t next_id_ = 0;

public:
    /**
     * @brief Connect to the bindable event.
     * 
     * @return A connection to the event.
     */
    std::shared_ptr<ScriptConnection> connect(std::function<void(Args...)> listener) override;

    /**
     * @brief Fires the event and runs the corresponding event handlers.
     */
    void fire(Args... args);

    /**
     * @brief Destructor.
     */
    ~BindableEvent() override;
};

#include "Events/BindableEvent.tpp"
