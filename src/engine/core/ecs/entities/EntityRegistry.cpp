/*
    EntityRegistry.cpp

    Implementation of an entity registry.
*/

#include "core/ecs/entities/EntityRegistry.hpp"

namespace toxico {
    EntityHandle EntityRegistry::create() {
        return entities_.emplace();
    }

    void EntityRegistry::remove(EntityHandle entity) {
        entities_.erase(entity);
    }

    bool EntityRegistry::isValid(EntityHandle entity) const {
        return entities_.isValid(entity);
    }

    const EntityData* EntityRegistry::getData(EntityHandle entity) const {
        return entities_.resolve(entity);
    }

    EntityData* EntityRegistry::getData(EntityHandle entity) {
        return entities_.resolve(entity);
    }
}
