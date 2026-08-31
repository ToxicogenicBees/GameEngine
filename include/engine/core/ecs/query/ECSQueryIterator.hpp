/*
    ECSQueryIterator.hpp

    Declaration of an ECS query iterator.
*/

#pragma once

#include "core/ecs/archetype/ArchetypePlacement.hpp"
#include "core/ecs/archetype/ArchetypeRegistry.hpp"
#include "core/ecs/query/ECSQueryContext.hpp"
#include "core/ecs/query/ECSQueryStorage.hpp"
#include "core/ecs/archetype/Signature.hpp"
#include "core/ecs/entity/EntityHandle.hpp"
#include "core/concepts/Component.hpp"
#include <tuple>

namespace toxico {
    template<Component... Components>
    class ECSQueryIterator {
    private:
        ComponentRegistry& components_;
        ECSQueryStorage<Components...> storage_;
        Signature signature_;

        /**
         * @brief Gets if this iterator position is valid.
         * 
         * @return If this iterator's position is valid.
         */
        bool valid_() const noexcept;

        /**
         * @brief Advances the internal archetype iterator to a valid position.
         */
        void advanceToValid_() noexcept;

        /**
         * @brief Increments this iterator.
         */
        void increment_() noexcept;

    public:
        /**
         * @brief Constructor.
         * 
         * @param context An ECS query context.
         * @param archetype The starting archetype to iterate from.
         * @param row The starting row to iterate from.
         * 
         * Throws an exception if the context is malformatted.
         */
        ECSQueryIterator(ECSQueryContext& context, ArchetypeRegistry::iterator archetype, ArchetypePlacement::index_type row) noexcept;

        /**
         * @brief Pre-increment operator.
         * 
         * @return The modified iterator.
         */
        ECSQueryIterator& operator++() noexcept;

        /**
         * @brief Dereference operator.
         * 
         * @return A tuple containing the entity handle and entity components for this iterator.
         */
        std::tuple<EntityHandle, Components&...> operator*() noexcept;

        /**
         * @brief Comparison operator.
         * 
         * @param other Another ECSQueryIterator.
         * @return If the two iterators are the same.
         */
        bool operator==(const ECSQueryIterator<Components...>& other) const noexcept;
    };
}

#include "core/ecs/query/ECSQueryIterator.tpp"
