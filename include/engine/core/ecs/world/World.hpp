/*
    World.hpp

    Declaration of a world, storing entities and their components.
*/

#pragma once

#include "core/ecs/components/ComponentRegistry.hpp"
#include "foundation/containers/SlotArray.hpp"
#include "foundation/containers/TypeMap.hpp"
#include "core/ecs/entities/EntityData.hpp"
#include "core/ecs/entities/EntityId.hpp"
#include <stdexcept>
#include <unordered_map>
#include <typeindex>
#include <memory>

namespace toxico {
    class World {
    private:
        ComponentRegistry components_;
        SlotArray<EntityData, EntityId> entities_;

    public:
        /**
         * @brief Creates an entity.
         * 
         * @return The created entity.
         */
        EntityId create() noexcept;

        /**
         * @brief Destroys an entity.
         * 
         * @return The created entity.
         */
        void destroy(EntityId entity) noexcept;

        /**
         * @brief Gets if the entity is valid.
         * 
         * @param entity The entity being validated.
         * @return If the entitiy is valid.
         */
        bool isValid(EntityId entity) const noexcept;

        /**
         * @brief Adds a component to an entity.
         * 
         * @param entity The entity being modified.
         * @param component The component being added.
         */
        template<typename Component>
        void addComponent(EntityId entity, Component component);

        /**
         * @brief Adds a component to an entity.
         * 
         * @param entity The entity being modified.
         * @param args The constructor arguments for the component.
         */
        template<typename Component, typename... Args>
        void addComponent(EntityId entity, Args&& ...args);

        /**
         * @brief Gets the component for a specific entity.
         * 
         * @param entity The entity having its component checked.
         * @return The entity's component, or nullptr if it doesn't own this component.
         */
        template<typename Component>
        Component* getComponent(EntityId entity) noexcept;

        /**
         * @brief Gets if an entity owns a specific component.
         * 
         * @param entity The entity being checked.
         * @return If this entity owns the desired component.
         */
        template<typename Component>
        bool hasComponent(EntityId entity) noexcept;

        /**
         * @brief Removes a component from an entity.
         * 
         * @param entity The entity being modified.
         */
        template<typename Component>
        void removeComponent(EntityId entity) noexcept;
    };
}

#include "core/ecs/world/World.tpp"
