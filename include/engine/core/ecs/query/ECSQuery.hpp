/*
    ECSQuery.hpp

    Declaration of a component query.
*/

#pragma once

#include "core/ecs/query/ECSQueryIterator.hpp"
#include "core/ecs/query/ECSQueryContext.hpp"
#include "core/concepts/Component.hpp"

namespace toxico {
    template<Component... Cs>
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
        ECSQueryIterator<Cs...> begin() noexcept;
        ECSQueryIterator<Cs...> end() noexcept;
    };
}

#include "core/ecs/query/ECSQuery.tpp"
