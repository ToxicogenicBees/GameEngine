/*
    Subsystem.tpp

    Template implementation of a subsystem class, in charge of initialization and shutdown.
*/

#pragma once

#include "Core/System/Subsystem.hpp"

template<typename Subsystem_t>
requires std::is_base_of_v<Subsystem, Subsystem_t>
size_t Subsystem::getSystemId() {
    static size_t id = next_id_++;
    return id;
}

template<typename Subsystem_t>
requires std::is_base_of_v<Subsystem, Subsystem_t>
void Subsystem::addDependency() {
    auto id = getSystemId<Subsystem_t>;
    dependencies_.emplace_back(id);
}
