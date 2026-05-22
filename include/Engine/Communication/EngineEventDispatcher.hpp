/*
    EngineEventDispatcher.hpp

    Declaration for an engine-level event dispatcher
*/

#pragma once

#include "Communication/Events/EngineEvent.hpp"
#include <unordered_map>
#include <functional>
#include <typeindex>
#include <memory>

class EngineEventDispatcher {
private:
    static std::unordered_map<std::type_index, std::vector<std::function<void(const EngineEvent&)>>> listeners_;

    /**
     * @brief Constructor (deleted)
     */
    EngineEventDispatcher() = delete;

public:
    /**
     * @brief Connect a listener to the dispatcher
     */
    template<typename EngineEvent_t>
    static void subscribe(std::function<void(const EngineEvent_t&)> listener) {
        listeners_[typeid(EngineEvent_t)].push_back(
            [listener](const EngineEvent& e) {
                listener(static_cast<const EngineEvent_t&>(e));
            }
        );
    }

    /**
     * @brief Dispatch an event to it's appropriate handler
     */
    static void dispatch(EngineEvent& event);
};
