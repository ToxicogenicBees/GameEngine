/*
    ComponentPool.tpp

    Template implementation of a component pool
*/

#include <algorithm>
#include <utility>

namespace toxico {
    template<typename Component>
    void ComponentPool<Component>::insert(EntityId entity, Component component) {
        // Allocate sparse set information
        sparse_.resize(entity.index() + 1, EntityId::invalid_index);

        // Insert the component into the system
        const auto dense_index = entities_.size();
        components_.push_back(std::move(component));
        entities_.push_back(entity);
        sparse_[entity.index()] = dense_index;
    }

    template<typename Component>
    template<typename... Args>
    void ComponentPool<Component>::emplace(EntityId entity, Args&& ...args) {
        // Allocate sparse set information
        sparse_.resize(entity.index() + 1, EntityId::invalid_index);

        // Insert the component into the system
        const auto dense_index = entities_.size();
        components_.emplace_back(std::forward<Args>(args)...);
        entities_.push_back(entity);
        sparse_[entity.index()] = dense_index;
    }

    template<typename Component>
    void ComponentPool<Component>::erase(EntityId entity) noexcept {
        // Early exit if the entity isn't contained in the pool
        if (!contains(entity))
            return;

        // Fetch entity state
        const auto dense_index = sparse_[entity.index()];
        const EntityId removed = entities_[dense_index];
        const size_t last = components_.size() - 1;

        // Swap elements in memory
        if (dense_index != last) {
            components_[dense_index] = std::move(components_[last]);
            entities_[dense_index] = entities_[last];
            sparse_[entities_[dense_index].index()] = dense_index;
        }

        // Erase the desired entity
        components_.pop_back();
        entities_.pop_back();
        sparse_[removed.index()] = EntityId::invalid_index;
    }

    template<typename Component>
    const Component* ComponentPool<Component>::get(EntityId entity) const noexcept {
        if (contains(entity)) {
            const auto dense_index = sparse_[entity.index()];
            return &components_[dense_index];
        }

        return nullptr;
    }

    template<typename Component>
    Component* ComponentPool<Component>::get(EntityId entity) noexcept {
        if (contains(entity)) {
            const auto dense_index = sparse_[entity.index()];
            return &components_[dense_index];
        }

        return nullptr;
    }

    template<typename Component>
    bool ComponentPool<Component>::contains(EntityId entity) const noexcept {
        // Index the sparse array
        if (entity.index() >= sparse_.size())
            return false;
        const auto dense_index = sparse_[entity.index()];

        if (dense_index == EntityId::invalid_index)
            return false;

        if (dense_index >= entities_.size())
            return false;

        if (entities_[dense_index] != entity)
            return false;

        return true;
    }

    template<typename Component>
    size_t ComponentPool<Component>::size() const noexcept {
        return components_.size();
    }

    template<typename Component>
    ComponentPool<Component>::const_iterator ComponentPool<Component>::cbegin() const noexcept {
        return components_.cbegin();
    }

    template<typename Component>
    ComponentPool<Component>::iterator ComponentPool<Component>::begin() const noexcept {
        return components_.begin();
    }

    template<typename Component>
    ComponentPool<Component>::iterator ComponentPool<Component>::begin() noexcept {
        return components_.begin();
    }

    template<typename Component>
    ComponentPool<Component>::const_iterator ComponentPool<Component>::cend() const noexcept {
        return components_.cend();
    }

    template<typename Component>
    ComponentPool<Component>::iterator ComponentPool<Component>::end() const noexcept {
        return components_.end();
    }

    template<typename Component>
    ComponentPool<Component>::iterator ComponentPool<Component>::end() noexcept {
        return components_.end();
    }
}
