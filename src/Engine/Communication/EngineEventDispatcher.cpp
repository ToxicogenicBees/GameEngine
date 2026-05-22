/*
    EngineEventDispatcher.cpp

    Implementation for an engine-level event dispatcher
*/

#include "Communication/EngineEventDispatcher.hpp"

std::unordered_map<std::type_index, std::vector<std::function<void(const EngineEvent&)>>> EngineEventDispatcher::listeners_;

/**
 * @brief Dispatch an event to it's appropriate handler
 */
void EngineEventDispatcher::dispatch(EngineEvent& event) {
    auto& special_listeners = listeners_[typeid(event)];
    for (auto& handler : special_listeners)
        handler(event);
}
