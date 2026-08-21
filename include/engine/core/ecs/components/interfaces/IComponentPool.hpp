/*
    IComponentPool.hpp

    An interface for a component pool.
*/

#pragma once

#include "core/ecs/entities/EntityId.hpp"
#include <cstddef>

namespace toxico {
    class IComponentPool {
    public:
        /**
         * @brief Removes this pool's component from the entity.
         * 
         * @param entity The entity having its component removed.
         */
        virtual void erase(EntityId entity) noexcept = 0;

        /**
         * @brief Gets if an entity owns a component in this pool.
         * 
         * @param entity The entity being checked.
         * @return If the entity owns a component of this type.
         */
        virtual bool contains(EntityId entity) const noexcept = 0;

        /**
         * @brief Gets the size of the component pool.
         * 
         * @return The size of the component pool.
         */
        virtual size_t size() const noexcept = 0;
        
        /**
         * @brief Destructor.
         */
        virtual ~IComponentPool() = default;
    };
}
