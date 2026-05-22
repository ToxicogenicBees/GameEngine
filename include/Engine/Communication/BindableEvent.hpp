/*
    BindableEvent.hpp

    Declaration for a message communication scheme
*/

#pragma once

#include "Communication/ScriptConnection.hpp"
#include <unordered_map>
#include <functional>
#include <mutex>

template<typename... Args>
class BindableEvent {
private:
    using Listener = std::function<void(Args...)>;

    std::unordered_map<size_t, Listener> listeners_;
    std::mutex listener_guard_;
    size_t next_id_ = 0;

public:
    ScriptConnection connect(std::function<void(Args...)> listener) {
        size_t id;
        {
            std::lock_guard<std::mutex> guard(listener_guard_);
            id = next_id_++;
            listeners_.emplace(id, std::move(listener));
        }

        return ScriptConnection([this, id]() {
            std::lock_guard<std::mutex> guard(listener_guard_);
            listeners_.erase(id);
        });
    }

    void fire(Args... args) {
        std::unordered_map<size_t, Listener> snapshot;
        {
            std::lock_guard<std::mutex> guard(listener_guard_);
            snapshot = listeners_;
        }

        for (auto& [_, listener] : snapshot)
            listener(args...);
    }
};
