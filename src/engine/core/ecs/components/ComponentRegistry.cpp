/*
    ComponentRegistry.cpp

    Implementation of a component registry.
*/

#include "core/ecs/components/ComponentRegistry.hpp"

namespace toxico {
    ComponentId ComponentRegistry::getId(const std::type_index& type_index) const {
        return ids_.index_of(type_index);
    }

    bool ComponentRegistry::hasId(const std::type_index& type_index) const noexcept {
        return ids_.contains(type_index);
    }

    std::unique_ptr<IComponentPool> ComponentRegistry::createStorage(ComponentId id) const {
        return factories_[id]();
    }

    size_t ComponentRegistry::size() const noexcept {
        return ids_.size();
    }
}
