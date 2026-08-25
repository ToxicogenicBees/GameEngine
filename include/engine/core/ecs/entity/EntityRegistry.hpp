/*
    EntityRegistry.hpp

    Declaration of an entity registry.
*/

#pragma once

#include "foundation/containers/SlotArray.hpp"
#include "core/ecs/entity/EntityData.hpp"
#include "core/ecs/entity/EntityHandle.hpp"

namespace toxico {
    class EntityRegistry {
    private:
        SlotArray<EntityData, EntityHandle> entities_;

    public:
        /**
         * @brief Creates an entity.
         * 
         * @return The id of the created entity.
         */
        EntityHandle create();

        /**
         * @brief Removes an entity from the registry.
         * 
         * @param entity The id of the removed entity.
         */
        void remove(EntityHandle entity);

        /**
         * @brief Gets if an entity is valid.
         * 
         * @param entity The entity being validated.
         * @return If the entity is valid.
         */
        bool isValid(EntityHandle entity) const;

        /**
         * @brief Gets the component for a specific entity.
         * 
         * @param entity The entity having its component checked.
         * @return The entity's data, or nullptr if the entity is invalid.
         */
        const EntityData* getData(EntityHandle entity) const;
        EntityData* getData(EntityHandle entity);
    };
}
