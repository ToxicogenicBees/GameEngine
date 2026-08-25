/*
    ECSQuery.tpp

    Template implementation of a component query.
*/

#include "core/ecs/archetype/ArchetypeRegistry.hpp"
#include "core/ecs/component/ComponentRegistry.hpp"

namespace toxico {
    template<Component... Components>
    ECSQuery<Components...>::ECSQuery(ECSQueryContext context)
        : context_(std::move(context)) {}

    template<Component... Components>
    ECSQueryIterator<Components...> ECSQuery<Components...>::begin() noexcept {
        // Fetch signature
        auto& components = context_.get<ComponentRegistry>();
        Signature signature;
        ([&]{
            auto id = components.template getId<Components>();
            signature.add(id);
        }(), ...);

        // Find first archetype matching this type
        auto& archetypes = context_.get<ArchetypeRegistry>();
        auto iter = archetypes.begin();

        while (iter != archetypes.end() && !iter->second->contains(signature))
            ++iter;
        
        return {
            context_,
            iter,
            ArchetypePlacement::index_type{0}
        };
    }

    template<Component... Components>
    ECSQueryIterator<Components...> ECSQuery<Components...>::end() noexcept {
        auto& archetypes = context_.get<ArchetypeRegistry>();
        return {
            context_,
            archetypes.end(),
            ArchetypePlacement::index_type{0}
        };
    }
}
