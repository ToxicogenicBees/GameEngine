/*
    BindableEvent.tpp

    Template implementation for a message communication scheme
*/

#include "Events/BindableEvent.hpp"

template<typename... Args>
std::shared_ptr<ScriptConnection> BindableEvent<Args...>::connect(std::function<void(Args...)> listener) {
    size_t id;
    {
        std::lock_guard<std::mutex> guard(mutex_);
        id = next_id_++;
        listeners_.emplace(id, std::move(listener));
    }

    auto connection = std::make_shared<ScriptConnection>([this, id]() {
        std::lock_guard<std::mutex> guard(mutex_);
        listeners_.erase(id);
    });

    {
        std::lock_guard<std::mutex> guard(mutex_);
        connections_[id] = connection;
    }
    return connection;
}

template<typename... Args>
void BindableEvent<Args...>::fire(Args... args) {
    std::unordered_map<size_t, Listener> snapshot;
    {
        std::lock_guard<std::mutex> guard(mutex_);
        snapshot = listeners_;
    }

    for (auto& [_, listener] : snapshot)
        listener(args...);
}

template<typename... Args>
BindableEvent<Args...>::~BindableEvent() {
    for (auto& [_, connection] : connections_)
        connection->disconnect();
}
