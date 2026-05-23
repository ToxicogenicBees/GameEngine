/*
    EngineEventQueue.cpp

    Implementatino for the event queue, which manages and dispatches engine events
*/

#include "Events/EngineEventQueue.hpp"
#include "Events/EngineEventDispatcher.hpp"

std::queue<std::unique_ptr<EngineEvent>> EngineEventQueue::queue_;
std::mutex EngineEventQueue::mutex_;

void EngineEventQueue::push(std::unique_ptr<EngineEvent> event) {
    std::lock_guard<std::mutex> lock(mutex_);
    queue_.push(std::move(event));
}

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
