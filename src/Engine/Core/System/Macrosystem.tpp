/*
    Macrosystem.tpp

    Template implementation of a macrosystem class, a special subsystem that is in charge of other subsystems.
*/

#pragma once

#include "Core/System/Macrosystem.hpp"

template<typename Subsystem_t, typename... Args>
requires std::is_base_of_v<Subsystem, Subsystem_t>
void Macrosystem::addSystem(Args&& ...args) {
    auto id = Subsystem::getSystemId<Subsystem_t>();
    subsystems_[id] = (std::make_unique<Subsystem_t>(std::forward<Args>(args)...));
    indegree_[id] = 0;

    for (size_t dep : subsystems_[id]->dependencies()) {
        reverse_graph_[dep].push_back(id);
        indegree_[id]++;
    }
}

template<typename Subsystem_t>
requires std::is_base_of_v<Subsystem, Subsystem_t>
Subsystem_t* Macrosystem::fetchSystem() {
    auto id = Subsystem::getSystemId<Subsystem_t>();
    return static_cast<Subsystem_t*>(subsystems_[id].get());
}
