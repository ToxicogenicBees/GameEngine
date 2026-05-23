/*
    EngineEventDispatcher.cpp

    Implementation for an engine-level event dispatcher
*/

#include "Events/EngineEventDispatcher.hpp"

void EngineEventDispatcher::dispatch(const EngineEvent& event)
{
    std::type_index type(typeid(event));

    std::vector<std::function<void(const EngineEvent&)>> copy;
    {
        std::lock_guard<std::mutex> lock(mutex_);

        auto it = listeners_.find(type);
        if (it == listeners_.end())
            return;

        for (auto& [id, fn] : it->second)
            copy.push_back(fn);
    }

    for (auto& fn : copy)
        fn(event);
}

void EngineEventDispatcher::unsubscribe(const EventSubscription& sub) {
    std::lock_guard<std::mutex> lock(mutex_);

    auto it = listeners_.find(sub.type);
    if (it == listeners_.end())
        return;

    it->second.erase(sub.id);
}
