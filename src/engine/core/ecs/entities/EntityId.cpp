/*
    EntityId.cpp

    Implementation of a light-weight Entity handle.
*/

#include "core/ecs/entities/EntityId.hpp"
namespace toxico {
    EntityId::EntityId(uint32_t index, uint32_t generation) noexcept
        : index_(index),
          generation_(generation)
    {}

    bool EntityId::operator==(EntityId other) const noexcept {
        return index_ == other.index_ && generation_ == other.generation_;
    }

    uint32_t EntityId::index() const noexcept {
        return index_;
    }

    uint32_t EntityId::generation() const noexcept {
        return generation_;
    }
}
