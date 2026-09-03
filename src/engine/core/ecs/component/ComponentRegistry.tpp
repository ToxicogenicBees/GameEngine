/*
    ComponentRegistry.tpp

    Template implementation of a component registry.
*/

#include "core/ecs/component/ComponentPool.hpp"

namespace toxico {
    template<Component C>
    ComponentId ComponentRegistry::insert() {
        // Register type into the system
        const auto [id, is_new] = ids_.insert(typeid(C));
        
        // Define a factory to create a component pool of this component type
        if (is_new) {
            factories_.push_back([] {
                return std::make_unique<ComponentPool<C>>();
            });
        }

        return id;
    }

    template<Component C>
    ComponentId ComponentRegistry::get() const {
        return get(typeid(C));
    }

    template<Component C>
    std::optional<ComponentId> ComponentRegistry::find() const noexcept {
        return find(typeid(C));
    }

    template<Component... Cs>
    Signature ComponentRegistry::createSignature() {
        Signature result;

        (result.add(insert<Cs>()), ...);

        return result;
    }
}
