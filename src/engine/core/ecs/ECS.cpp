/*
    ECS.cpp

    Implementation of an ECS, storing entities and their components.
*/

#include "core/ecs/ECS.hpp"

namespace toxico {
    EntityId ECS::create() noexcept {
        return entities_.emplace();
    }

    void ECS::destroy(EntityId entity) noexcept {
        components_.remove(entity);
        entities_.erase(entity);
    }

    bool ECS::isValid(EntityId entity) const noexcept {
        return entities_.isValid(entity);
    }
}
