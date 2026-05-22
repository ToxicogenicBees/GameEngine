/*
    EngineEventQueue.hpp

    Declaration for the event queue, which manages and dispatches engine events
*/

#pragma once

#include "Communication/Events/EngineEvent.hpp"
#include <queue>
#include <memory>
#include <mutex>

class EngineEventQueue {
private:
    static std::queue<std::unique_ptr<EngineEvent>> queue_;
    static std::mutex mutex_;

    /**
     * @brief Constructor (deleted)
     */
    EngineEventQueue() = delete;

public:
    /**
     * @brief Push an engine event onto the queue
     * 
     * @param event The engine event being put into the queue
     */
    static void push(std::unique_ptr<EngineEvent> event);

    /**
     * @brief Dispatch all events in the queue
     */
    static void dispatch();
};
