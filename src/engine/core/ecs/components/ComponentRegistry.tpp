/*
    ComponentRegistry.tpp

    Template implementation of a component registry.
*/

#include "core/ecs/components/ComponentPool.hpp"

namespace toxico {
    template<Component C>
    void ComponentRegistry::insert() {
        // Register type into the system
        const auto [_, is_new] = ids_.insert(typeid(C));
        
        // Define a factory to create a component pool of this component type
        if (is_new) {
            factories_.push_back([] {
                return std::make_unique<ComponentPool<C>>();
            });
        }
    }

    template<Component C>
    ComponentId ComponentRegistry::getId() const {
        return getId(typeid(C));
    }

    template<Component C>
    bool ComponentRegistry::hasId() const noexcept {
        return hasId(typeid(C));
    }
}
