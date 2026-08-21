/*
    World.cpp

    Implementation of a world, storing entities and their components.
*/

#include "core/ecs/world/World.hpp"

namespace toxico {
    EntityId World::create() noexcept {
        return entities_.emplace();
    }

    void World::destroy(EntityId entity) noexcept {
        components_.remove(entity);
        entities_.erase(entity);
    }

    bool World::isValid(EntityId entity) const noexcept {
        return entities_.isValid(entity);
    }
}
