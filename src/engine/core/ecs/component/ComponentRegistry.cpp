/*
    ComponentRegistry.cpp

    Implementation of a component registry.
*/

#include "core/ecs/component/ComponentRegistry.hpp"

namespace toxico {
    ComponentId ComponentRegistry::get(const std::type_index& type) const {
        auto id = ids_.index_of(type);
        if (id == ids_.invalid_index)
            throw std::invalid_argument("Cannot get id of unregistered type");

        return id;
    }

    std::optional<ComponentId> ComponentRegistry::find(const std::type_index& type) const noexcept {
        if (ids_.contains(type))
            return ids_.index_of(type);

        return std::nullopt;
    }

    std::unique_ptr<IComponentPool> ComponentRegistry::createStorage(ComponentId id) const {
        return factories_[id]();
    }

    std::size_t ComponentRegistry::size() const noexcept {
        return ids_.size();
    }
}
