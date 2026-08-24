/*
    ECS.hpp

    Declaration of an ECS, storing entities and their components.
*/

#pragma once

#include "core/interfaces/ICoreModule.hpp"
#include "core/ecs/components/concepts/Component.hpp"
#include "core/ecs/archetypes/ArchetypeRegistry.hpp"
#include "core/ecs/archetypes/ArchetypePlacement.hpp"
#include "core/ecs/components/ComponentRegistry.hpp"
#include "core/ecs/entities/EntityRegistry.hpp"
#include "core/ecs/entities/EntityHandle.hpp"
#include <typeindex>
#include <memory>

namespace toxico {
    class ECS : public ICoreModule {
    private:
        ComponentRegistry components_;
        ArchetypeRegistry archetypes_;
        EntityRegistry entities_;

        /**
         * @brief Moves an entity from one architype to another.
         * 
         * @param entity The entity being moved.
         * @param destination The destination for the entity.
         */
        ArchetypePlacement moveEntity_(EntityHandle entity, const Signature& destination);

    public:
        /**
         * @brief Constructor.
         */
        ECS();

        /**
         * @brief Creates an entity.
         * 
         * @return The created entity.
         */
        template<Component... Components>
        EntityHandle create(const Components& ...components) noexcept;

        /**
         * @brief Creates an entity with default-initialized components.
         * 
         * @return The created entity.
         */
        template<Component... Components>
        EntityHandle create() noexcept;

        /**
         * @brief Destroys an entity.
         * 
         * @param entity The entity being destroyed.
         */
        void destroy(EntityHandle entity) noexcept;

        /**
         * @brief Gets if the entity is valid.
         * 
         * @param entity The entity being validated.
         * @return If the entitiy is valid.
         */
        bool isValid(EntityHandle entity) const noexcept;

        /**
         * @brief Adds a component to an entity.
         * 
         * @param entity The entity being modified.
         * @param component The component being added.
         * 
         * Throws an invalid argument exception if the entity is invalid.
         */
        template<Component C>
        void addComponent(EntityHandle entity, const C& component);

        /**
         * @brief Adds a component to an entity.
         * 
         * @param entity The entity being modified.
         * @param args The constructor arguments for the component.
         * 
         * Throws an invalid argument exception if the entity is invalid.
         */
        template<Component C, typename... Args>
        void addComponent(EntityHandle entity, Args&& ...args);

        /**
         * @brief Gets the component for a specific entity.
         * 
         * @param entity The entity having its component checked.
         * @return The entity's component, or nullptr if it doesn't own this component.
         */
        template<Component C>
        const C* getComponent(EntityHandle entity) const noexcept;
        template<Component C>
        C* getComponent(EntityHandle entity) noexcept;

        /**
         * @brief Gets the data for a specific entity.
         * 
         * @param entity The entity having its data fetched.
         * @return The entity's data, or nullptr if the entity is invalid.
         */
        const EntityData* getData(EntityHandle entity) const;
        EntityData* getData(EntityHandle entity);

        /**
         * @brief Gets if an entity owns a specific component.
         * 
         * @param entity The entity being checked.
         * @return If this entity owns the desired component.
         */
        template<Component C>
        bool hasComponent(EntityHandle entity) noexcept;

        /**
         * @brief Removes a component from an entity.
         * 
         * @param entity The entity being modified.
         * 
         * Throws an invalid argument exception if the entity is invalid.
         */
        template<Component C>
        void removeComponent(EntityHandle entity) noexcept;
    };
}

#include "core/ecs/ECS.tpp"
