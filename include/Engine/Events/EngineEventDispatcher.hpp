/*
    EngineEventDispatcher.hpp

    Declaration for an engine-level event dispatcher
*/

#pragma once

#include "Events/EventSubscription.hpp"
#include "Events/EngineEvent.hpp"
#include <unordered_map>
#include <functional>
#include <typeindex>
#include <vector>
#include <memory>
#include <mutex>

class EngineEventDispatcher {
private:
    using ListenerFn = std::function<void(const EngineEvent&)>;

    inline static std::unordered_map<std::type_index, std::unordered_map<size_t, ListenerFn>> listeners_;
    inline static size_t next_id_ = 0;
    inline static std::mutex mutex_;

    /**
     * @brief Constructor (deleted).
     */
    EngineEventDispatcher() = delete;

public:
    /**
     * @brief Subscribe to an engine event.
     * 
     * @param listener The listener function called when an event of the desired type is dispatched.
     * @return A unique subscription for this listener.
     */
    template<typename Event_t>
    static std::unique_ptr<EventSubscription> subscribe(std::function<void(const Event_t&)> listener);

    /**
     * @brief Dispatches the desired event to all relevant listeners.
     * 
     * @param event The event to be dispatched.
     */
    static void dispatch(const EngineEvent& event);

    /**
     * @brief Unsubscribes from an engine event.
     * 
     * @param subscription The subscription being terminated.
     */
    static void unsubscribe(std::unique_ptr<EventSubscription> subscription);
};

#include "Events/EngineEventDispatcher.tpp"
