/*
    ComponentPool.hpp

    Declaration of a component pool
*/

#pragma once

#include "core/ecs/components/interfaces/IComponentPool.hpp"
#include "core/ecs/entities/EntityId.hpp"
#include <vector>
#include <limits>

namespace toxico {
    template<typename Component>
    class ComponentPool final : public IComponentPool {
    private:
        std::vector<Component> components_;
        std::vector<EntityId> entities_;
        std::vector<EntityId::index_type> sparse_;

    public:
        using const_iterator = std::vector<Component>::const_iterator;
        using iterator = std::vector<Component>::iterator;

        /**
         * @brief Inserts a component into a given entity.
         * 
         * @param entity The entity the component is being added to.
         * @param component The component being added to the entity.
         */
        void insert(EntityId entity, Component component);

        /**
         * @brief Emplaces a component into a given entity.
         * 
         * @param entity The entity the component is being added to.
         * @param args Constructor arguments for the component.
         */
        template<typename... Args>
        void emplace(EntityId entity, Args&& ...args);

        /**
         * @brief Removes this pool's component from the entity.
         * 
         * @param entity The entity having its component removed.
         */
        void erase(EntityId entity) noexcept final;

        /**
         * @brief Gets the component for a specific entity.
         * 
         * @param entity The entity having its component checked.
         * @return The entity's component, or nullptr if it doesn't own this component.
         */
        const Component* get(EntityId entity) const noexcept;
        Component* get(EntityId entity) noexcept;

        /**
         * @brief Gets if an entity owns a component in this pool.
         * 
         * @param entity The entity being checked.
         * @return If the entity owns a component of this type.
         */
        bool contains(EntityId entity) const noexcept final;

        /**
         * @brief Gets the size of the component pool.
         * 
         * @return The size of the component pool.
         */
        size_t size() const noexcept final;

        /**
         * @brief Gets the desired iterator for this pool's components.
         * 
         * @return The desired iterator.
         */
        const_iterator cbegin() const noexcept;
        iterator begin() const noexcept;
        iterator begin() noexcept;
        const_iterator cend() const noexcept;
        iterator end() const noexcept;
        iterator end() noexcept;
    };
}

#include "core/ecs/components/ComponentPool.tpp"
