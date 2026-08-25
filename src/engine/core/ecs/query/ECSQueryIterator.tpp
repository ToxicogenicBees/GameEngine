/*
    ECSQueryIterator.tpp

    Template implementation of an ECS query iterator.
*/

#include "core/ecs/component/ComponentPool.hpp"

namespace toxico {
    template<Component... Components>
    ECSQueryIterator<Components...>::ECSQueryIterator(ECSQueryContext& context, ArchetypeRegistry::iterator archetype, ArchetypePlacement::index_type row) noexcept
        : archetypes_(context.get<ArchetypeRegistry>()),
          components_(context.get<ComponentRegistry>()),
          storage_({
            .archetype_iter = archetype,
            .row = row
          })
    {
        // Fetch signature and populate component pool storage
        ([&]{
            auto id = components_.template getId<Components>();
            signature_.add(id);
        }(), ...);

        // Update component pool cache
        if (storage_.archetype_iter != archetypes_.end() && storage_.archetype_iter->second->contains(signature_)) {
            ([&]{
                auto id = components_.template getId<Components>();
                auto* typeless = storage_.archetype_iter->second->getPool(id);
                std::get<ComponentPool<Components>*>(storage_.pools) = static_cast<ComponentPool<Components>*>(typeless);
            }(), ...);
        }
    }

    template<Component... Components>
    ECSQueryIterator<Components...>& ECSQueryIterator<Components...>::operator++() noexcept {
        // Move along inside the archetype
        if (++storage_.row >= storage_.archetype_iter->second->size()) {
            // Reached the end of the row, find the next valid archetype
            storage_.row = 0;
            while (
                ++storage_.archetype_iter != archetypes_.end()
                && !storage_.archetype_iter->second->contains(signature_)
            );

            // Update component pool cache
            if (storage_.archetype_iter != archetypes_.end()) {
                ([&]{
                    auto id = components_.template getId<Components>();
                    auto* typeless = storage_.archetype_iter->second->getPool(id);
                    std::get<ComponentPool<Components>*>(storage_.pools) = static_cast<ComponentPool<Components>*>(typeless);
                }(), ...);
            }
        }

        return *this;
    }

    template<Component... Components>
    std::tuple<EntityHandle, Components&...> ECSQueryIterator<Components...>::operator*() noexcept {
        return {
            storage_.archetype_iter->second->getEntity(storage_.row),
            (*std::get<ComponentPool<Components>*>(storage_.pools))[storage_.row]...
        };
    }

    template<Component... Components>
    bool ECSQueryIterator<Components...>::operator==(const ECSQueryIterator<Components...>& other) const noexcept {
        return &archetypes_ == &other.archetypes_
            && &components_ == &other.components_
            && storage_.archetype_iter == other.storage_.archetype_iter
            && storage_.row == other.storage_.row;
    }
}
