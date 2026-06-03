/*
    BindableEvent.tpp

    Template implementation for a message communication scheme
*/

#include "Events/BindableEvent.hpp"
#include <iostream>

template<typename... Args>
ScriptConnection BindableEvent<Args...>::connect(IBindableEvent<Args...>::Func fn, int priority) {
    auto id = Guid();

    entries_.push_back({priority, id, std::move(fn)});

    std::sort(entries_.begin(), entries_.end(), [](auto& a, auto& b) {
        return a.priority > b.priority;
    });

    return ScriptConnection([this, id]() {
        std::erase_if(entries_, [&](auto& e) {
            return e.id == id;
        });
    });
}

template<typename... Args>
void BindableEvent<Args...>::fire(Args... args) {
    for (auto& e : entries_)
        e.fn(args...);
}
