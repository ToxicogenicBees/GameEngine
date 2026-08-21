/*
    ComponentRegistry.hpp

    Declaration of a component registry.
*/

#pragma once

#include "core/ecs/components/interfaces/IComponentPool.hpp"
#include "core/ecs/components/ComponentPool.hpp"
#include "core/ecs/entities/EntityId.hpp"
#include "foundation/containers/TypeMap.hpp"

namespace toxico {
    class ComponentRegistry {
    private:
        TypeMap<IComponentPool> pools_;

    public:
        /**
         * @brief Adds a component to an entity.
         * 
         * @param entity The entity being modified.
         * @param component The component being added.
         */
        template<typename Component>
        void add(EntityId entity, Component component);

        /**
         * @brief Adds a component to the desired entity.
         * 
         * @param entity The entity this component is being added to.
         * @param args The constructor arguments for the given component.
         */
        template<typename Component, typename... Args>
        void add(EntityId entity, Args&& ...args);

        /**
         * @brief Gets if an entity owns a specific component.
         * 
         * @param entity The entity being checked.
         * @return If this entity owns the desired component.
         */
        template<typename Component>
        bool has(EntityId entity) const noexcept;

        /**
         * @brief Gets the component owned by an entity.
         * 
         * @param entity The entity that owns this component.
         * @return The component, or nullptr if this entity
         *         doesn't own a component of that type.
         */
        template<typename Component>
        const Component* get(EntityId entity) const noexcept;
        template<typename Component>
        Component* get(EntityId entity) noexcept;

        /**
         * @brief Removes the desired components of an entity.
         * 
         * @param entity The entity the component is being removed from.
         */
        template<typename Component>
        void remove(EntityId entity) noexcept;

        /**
         * @brief Removes all components of an entity.
         * 
         * @param entity The entity the components are being removed from.
         */
        void remove(EntityId entity) noexcept;
    };
}

#include "core/ecs/components/ComponentRegistry.tpp"
