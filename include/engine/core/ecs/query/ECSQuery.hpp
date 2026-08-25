/*
    ECSQuery.hpp

    Declaration of a component query.
*/

#pragma once

#include "core/ecs/components/concepts/Component.hpp"
#include "core/ecs/archetypes/ArchetypeRegistry.hpp"
#include "core/ecs/components/ComponentRegistry.hpp"
#include "core/ecs/query/ECSQueryIterator.hpp"
#include "core/ecs/query/ECSQueryContext.hpp"
#include "foundation/Context.hpp"

namespace toxico {
    template<Component... Components>
    class ECSQuery {
    private:
        ECSQueryContext context_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param context An ECS query context.
         * 
         * Throws an exception if the context is malformatted.
         */
        ECSQuery(ECSQueryContext context);

        /**
         * @brief Gets the desired iterator for this query.
         * 
         * @return The desired iterator.
         */
        ECSQueryIterator<Components...> begin() noexcept;
        ECSQueryIterator<Components...> end() noexcept;
    };
}

#include "core/ecs/query/ECSQuery.tpp"
