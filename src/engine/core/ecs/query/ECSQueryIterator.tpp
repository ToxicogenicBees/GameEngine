/*
    ECSQueryIterator.tpp

    Template implementation of an ECS query iterator.
*/

#include "core/ecs/component/ComponentPool.hpp"

namespace toxico {

    template<Component... Cs>
    bool ECSQueryIterator<Cs...>::valid_() const noexcept {
        // end() is never a valid dereferenceable position.
        if (storage_.current == storage_.end)
            return false;

        // Archetype must have all desired components and not be empty
        const auto& archetype = storage_.current->second;
        return !archetype->empty() && archetype->contains(signature_);
    }

    template<Component... Cs>
    void ECSQueryIterator<Cs...>::advanceToValid_() noexcept {
        while (storage_.current != storage_.end && !valid_())
            ++storage_.current;

        if (storage_.current != storage_.end) {
            ([&] {
                auto id = components_.template find<Cs>();
                auto* typeless = storage_.current->second->getPool(*id);
                std::get<ComponentPool<Cs>*>(storage_.pools) = static_cast<ComponentPool<Cs>*>(typeless);
            }(), ...);
        }
    }

    template<Component... Cs>
    void ECSQueryIterator<Cs...>::increment_() noexcept {
        // Don't operate on an end iterator.
        if (storage_.current == storage_.end)
            return;

        // Advance within the current archetype.
        ++storage_.row;

        // Still have entities remaining in this archetype.
        if (storage_.row < storage_.current->second->size())
            return;

        // Current archetype exhausted. Move to the next one.
        storage_.row = 0;
        ++storage_.current;

        // Find the next archetype that satisfies the query.
        advanceToValid_();
    }

    template<Component... Cs>
    ECSQueryIterator<Cs...>::ECSQueryIterator(ECSQueryContext& context, ArchetypeRegistry::iterator archetype, ArchetypePlacement::index_type row) noexcept
        : components_(context.get<ComponentRegistry>()),
          storage_({
              .current = archetype,
              .end = context.get<ArchetypeRegistry>().end(),
              .row = row
          })
    {
        // Build the signature required by this query.
        signature_ = components_.template createSignature<Cs...>();

        // If we weren't given end(), find the first valid position.
        if (storage_.current != storage_.end)
            advanceToValid_();
    }

    template<Component... Cs>
    ECSQueryIterator<Cs...>& ECSQueryIterator<Cs...>::operator++() noexcept {
        increment_();
        return *this;
    }

    template<Component... Cs>
    std::tuple<EntityHandle, Cs&...> ECSQueryIterator<Cs...>::operator*() noexcept {
        return {
            storage_.current->second->getEntity(storage_.row),
            (*std::get<ComponentPool<Cs>*>(storage_.pools))[storage_.row]...
        };
    }

    template<Component... Cs>
    bool ECSQueryIterator<Cs...>::operator==(const ECSQueryIterator<Cs...>& other) const noexcept {
        return storage_.current == other.storage_.current
            && storage_.row == other.storage_.row;
    }
}
