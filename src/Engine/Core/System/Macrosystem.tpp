/*
    Macrosystem.tpp

    Template implementation of a macrosystem class, a special subsystem that is in charge of other subsystems.
*/

#pragma once

#include "Core/System/Macrosystem.hpp"

template<typename Subsystem_t>
requires std::is_base_of_v<Subsystem, Subsystem_t>
void Macrosystem::addSystem(std::unique_ptr<Subsystem_t> subsystem) {
    auto id = subsystem->id();
    nodes_[id] = subsystem->get();
    indegree_[id] = 0;

    for (size_t dep : subsystem->dependencies()) {
        reverse_graph_[dep].push_back(id);
        indegree_[id]++;
    }

    subsystems_.push_back(std::move(subsystem));
}

template<typename Subsystem_t>
requires std::is_base_of_v<Subsystem, Subsystem_t>
Subsystem_t* Macrosystem::fetchSystem() {
    auto id = Subsystem::getSystemId<Subsystem_t>;
    return subsystems_.at(id);
}
