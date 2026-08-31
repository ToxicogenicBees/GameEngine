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
            components_.push_back({
                .id = component_id,
                .pool = component_registry.createStorage(component_id),
            });
        }
    }

    ArchetypePlacement Archetype::create(EntityHandle entity) noexcept {
        // Cache index
        const ArchetypePlacement::index_type row = components_.empty() ? 0 : components_.front().pool->size();

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

    Archetype::EraseResult Archetype::erase(ArchetypePlacement::index_type row) noexcept {
        // Early exit if row isn't held in this archetype
        if (row >= entities_.size())
            return {};

        // Handle trivial case: removed item's components are at the end of their lists
        auto last = entities_.size() - 1;
        if (row == last) {
            // Erase old entity
            entities_.pop_back();

            // Erase old components
            for (auto& storage : components_)
                storage.pool->pop_back();

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
        auto it = std::lower_bound(
            components_.begin(),
            components_.end(),
            id,
            [](const ComponentStorage& storage, ComponentId id) {
                return storage.id < id;
            }
        );

        if (it == components_.end() || it->id != id)
            return nullptr;
        return it->pool.get();
    }

    IComponentPool* Archetype::getPool(ComponentId id) noexcept {
        auto it = std::lower_bound(
            components_.begin(),
            components_.end(),
            id,
            [](const ComponentStorage& storage, ComponentId id) {
                return storage.id < id;
            }
        );

        if (it == components_.end() || it->id != id)
            return nullptr;
        return it->pool.get();
    }

    bool Archetype::contains(const Signature& signature) const {
        auto iter = signature.begin();

        for (auto id : signature_) {
            if (iter == signature.end())
                return true;

            if (*iter == id)
                ++iter;
            else if (*iter < id)
                return false;
        }

        return iter == signature.end();
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
