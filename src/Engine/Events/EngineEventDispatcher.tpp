/*
    EngineEventDispatcher.tpp

    Template implementation for an engine-level event dispatcher
*/

#include "Events/EngineEventDispatcher.hpp"

template<typename Event_t>
std::unique_ptr<EventSubscription> EngineEventDispatcher::subscribe(std::function<void(const Event_t&)> listener) {
    std::lock_guard<std::mutex> lock(mutex_);

    size_t id = next_id_++;

    listeners_[typeid(Event_t)][id] =
        [listener](const EngineEvent& e) {
            listener(static_cast<const Event_t&>(e));
        };

    return std::make_unique<EventSubscription>(typeid(Event_t), id);
}
