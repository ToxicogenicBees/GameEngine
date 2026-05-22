/*
    EngineEventQueue.cpp

    Implementatino for the event queue, which manages and dispatches engine events
*/

#include "Communication/EngineEventQueue.hpp"
#include "Communication/EngineEventDispatcher.hpp"

std::queue<std::unique_ptr<EngineEvent>> EngineEventQueue::queue_;
std::mutex EngineEventQueue::mutex_;

/**
 * @brief Push an engine event onto the queue
 * 
 * @param event The engine event being put into the queue
 */
void EngineEventQueue::push(std::unique_ptr<EngineEvent> event) {
    std::lock_guard<std::mutex> lock(mutex_);
    queue_.push(std::move(event));
}

/**
 * @brief Dispatch all events in the queue
 */
void EngineEventQueue::dispatch() {
    std::queue<std::unique_ptr<EngineEvent>> local;
    {
        std::lock_guard<std::mutex> lock(mutex_);
        std::swap(local, queue_);
    }

    while (!local.empty()) {
        EngineEventDispatcher::dispatch(*local.front());
        local.pop();
    }
}
