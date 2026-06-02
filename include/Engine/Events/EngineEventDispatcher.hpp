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

    EngineEventDispatcher() = delete;

public:
    template<typename Event_t>
    static std::unique_ptr<EventSubscription> subscribe(std::function<void(const Event_t&)> listener) {
        std::lock_guard<std::mutex> lock(mutex_);

        size_t id = next_id_++;

        listeners_[typeid(Event_t)][id] =
            [listener](const EngineEvent& e) {
                listener(static_cast<const Event_t&>(e));
            };

        return std::make_unique<EventSubscription>(typeid(Event_t), id);
    }

    static void dispatch(const EngineEvent& event);

    static void unsubscribe(std::unique_ptr<EventSubscription> subscription);
};
