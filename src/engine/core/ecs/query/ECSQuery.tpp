/*
    ECSQuery.tpp

    Template implementation of a component query.
*/

#include "core/ecs/archetype/ArchetypeRegistry.hpp"
#include "core/ecs/component/ComponentRegistry.hpp"

namespace toxico {
    template<Component... Cs>
    ECSQuery<Cs...>::ECSQuery(ECSQueryContext context)
        : context_(std::move(context)) {}

    template<Component... Cs>
    ECSQueryIterator<Cs...> ECSQuery<Cs...>::begin() noexcept {
        auto& archetypes = context_.get<ArchetypeRegistry>();
        return {
            context_,
            archetypes.begin(),
            ArchetypePlacement::index_type{0}
        };
    }

    template<Component... Cs>
    ECSQueryIterator<Cs...> ECSQuery<Cs...>::end() noexcept {
        auto& archetypes = context_.get<ArchetypeRegistry>();
        return {
            context_,
            archetypes.end(),
            ArchetypePlacement::index_type{0}
        };
    }
}
