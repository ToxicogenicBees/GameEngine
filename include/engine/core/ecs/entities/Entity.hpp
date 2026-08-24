/*
    Entity.hpp

    Declaration of an ECS entity wrapper.
*/

#pragma once

#include "core/ecs/entities/EntityHandle.hpp"
#include "core/ecs/ECS.hpp"

namespace toxico {
    class Entity {
    private:
        EntityHandle handle_;
        ECS& ecs_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param ecs The ECS controlling this entity.
         * @param handle The handle for this entity.
         */
        Entity(ECS& ecs, EntityHandle handle) noexcept;

        /**
         * @brief Destroys the entity.
         */
        void destroy() noexcept;

        /**
         * @brief Gets if the entity is valid.
         * 
         * @return If the entitiy is valid.
         */
        bool isValid() const noexcept;

        /**
         * @brief Adds a component to an entity.
         * 
         * @param entity The entity being modified.
         * @param component The component being added.
         * 
         * Throws an invalid argument exception if the entity is invalid.
         */
        template<Component C>
        void add(const C& component);

        /**
         * @brief Adds a component to an entity.
         * 
         * @param entity The entity being modified.
         * @param args The constructor arguments for the component.
         * 
         * Throws an invalid argument exception if the entity is invalid.
         */
        template<Component C, typename... Args>
        void add(Args&& ...args);

        /**
         * @brief Gets the component for a specific entity.
         * 
         * @return The entity's component, or nullptr if it doesn't own this component.
         */
        template<Component C>
        const C* get() const noexcept;
        template<Component C>
        C* get() noexcept;

        /**
         * @brief Gets if an entity owns a specific component.
         * 
         * @return If this entity owns the desired component.
         */
        template<Component C>
        bool has() noexcept;

        /**
         * @brief Removes a component from an entity.
         * 
         * Throws an invalid argument exception if the entity is invalid.
         */
        template<Component C>
        void remove() noexcept;

        /**
         * @brief Gets this entity's handle.
         * 
         * @return This entity's handle
         */
        EntityHandle handle() const noexcept;
    };
}

#include "core/ecs/entities/Entity.tpp"
