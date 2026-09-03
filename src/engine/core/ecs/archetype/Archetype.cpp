/*
    Archetype.cpp

    Implementation of an ECS archetype.
*/

#include "core/ecs/archetype/Archetype.hpp"

namespace toxico {
    Archetype::Archetype(const ComponentRegistry& component_registry, const Signature& signature) noexcept
        : signature_(signature)
    {
        // Create (sorted) storage for each id in the signature
        for (const auto& component_id : signature) {
            components_.insert(
                component_id,
                std::move(component_registry.createStorage(component_id))
            );
        }
    }

    ArchetypePlacement Archetype::create(EntityHandle entity) noexcept {
        // Cache index
        const ArchetypePlacement::index_type row = entities_.size();

        // Add a default-initialized component for each slot
        for (auto& [_, pool] : components_)
            pool->push_back();

        // Store entity handle
        entities_.push_back(entity);

        // Give a placement for this new entity
        return ArchetypePlacement{
            .signature = signature_,
            .row = row,
        };
    }

    ArchetypeEraseResult Archetype::erase(ArchetypePlacement::index_type row) noexcept {
        // Early exit if row isn't held in this archetype
        if (row >= entities_.size())
            return {};

        // Handle trivial case: removed item's components are at the end of their lists
        auto last = entities_.size() - 1;
        if (row == last) {
            // Erase old entity
            entities_.pop_back();

            // Erase old components
            for (auto& [_, pool] : components_)
                pool->pop_back();

            return {};
        }

        // Erase old entity
        entities_.erase(static_cast<std::size_t>(row));
        for (auto& [_, pool] : components_)
            pool->erase(row);

        return {
            .moved = entities_[row],
            .placement = {
                .signature = signature_,
                .row = row,
            }
        };
    }

    EntityHandle Archetype::getEntity(ArchetypePlacement::index_type row) const {
        if (row >= entities_.size())
            throw std::out_of_range("Attempted to index entity outside of archetype range: " + std::to_string(row));
        return entities_[row];
    }

    const IComponentPool* Archetype::getPool(ComponentId id) const noexcept {
        auto result = components_.find(id);
        if (result != components_.end())
            return result->second.get();

        return nullptr;
    }

    IComponentPool* Archetype::getPool(ComponentId id) noexcept {
        auto result = components_.find(id);
        if (result != components_.end())
            return result->second.get();

        return nullptr;
    }

    bool Archetype::contains(const Signature& signature) const {
        return signature_.contains(signature);
    }

    const Signature& Archetype::signature() const noexcept {
        return signature_;
    }

    ArchetypePlacement::index_type Archetype::size() const noexcept {
        return entities_.size();
    }

    bool Archetype::empty() const noexcept {
        return entities_.empty();
    }
}
