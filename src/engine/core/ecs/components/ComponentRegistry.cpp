/*
    ComponentRegistry.cpp

    Implementation of a component registry.
*/

#include "core/ecs/components/ComponentRegistry.hpp"

namespace toxico {
    void ComponentRegistry::remove(EntityId entity) noexcept {
        for (auto& [_, pool] : pools_)
            pool->erase(entity);
    }
}
