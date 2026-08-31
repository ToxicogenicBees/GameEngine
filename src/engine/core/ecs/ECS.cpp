/*
    ECS.cpp

    Implementation of an ECS, storing entities and their components.
*/

#include "core/ecs/ECS.hpp"

namespace toxico {
    ECS::ECS()
        : components_(),
          archetypes_(components_),
          entities_()
    {}

    ArchetypePlacement ECS::moveEntity_(EntityHandle entity, const Signature& destination) {
        // Fetch old entity data
        auto* data = entities_.getData(entity);
        const auto& old_signature = data->placement.signature;
        const auto old_row = data->placement.row;

        // Ensure the destination is different
        if (old_signature == destination)
            return data->placement;

        // Fetch archetypes
        auto& src_archetype = archetypes_.fetch(old_signature);
        auto& dest_archetype = archetypes_.fetch(destination);

        // Create the components for the entity
        auto placement = dest_archetype.create(entity);

        // Copy the entity's old components over
        for (auto id : old_signature) {
            // Fetch pools for this id
            auto* src_pool = src_archetype.getPool(id);
            auto* dest_pool = dest_archetype.getPool(id);

            // Copy over the old components, assuming the new architype owns it
            if (dest_pool)
                src_pool->copyTo(*dest_pool, old_row, placement.row);
        }

        // Erase the old entity
        auto result = src_archetype.erase(old_row);
        if (result.moved) {
            // Update any shifted entity data due to the dense component vectors
            auto* moved_data = entities_.getData(*result.moved);
            moved_data->placement = result.placement;
        }

        // Update the entity's data
        data = entities_.getData(entity);
        data->placement = placement;

        return placement;
    }

    EntityHandle ECS::clone(EntityHandle original) {
        // Return the original if the original entity isn't valid.
        if (!isValid(original)) {
            return EntityHandle{
                EntityHandle::invalid_index,
                EntityHandle::invalid_index
            };
        }

        // Create a new entity
        auto clone = create();

        // Move the clone into the appropriate archetype
        auto* orig_data = entities_.getData(original);
        moveEntity_(clone, orig_data->placement.signature);
        auto* clone_data = entities_.getData(clone);

        // Copy the components over
        auto& archetype = archetypes_.fetch(orig_data->placement.signature);
        for (auto id : orig_data->placement.signature) {
            // Copy component for this component id
            auto* pool = archetype.getPool(id);
            pool->copyTo(orig_data->placement.row, clone_data->placement.row);
        }

        return clone;
    }

    void ECS::destroy(EntityHandle entity) noexcept {
        if (!isValid(entity))
            return;

        // Remove entity from ArchetypeRegistry
        auto* data = entities_.getData(entity);
        auto& archetype = archetypes_.fetch(data->placement.signature);
        auto result = archetype.erase(data->placement.row);

        // Move any modified entities
        if (result.moved) {
            // Update any shifted entity data due to the dense component vectors
            auto* moved_data = entities_.getData(*result.moved);
            moved_data->placement = result.placement;
        }

        // Remove entity from EntityRegistry
        entities_.remove(entity);
    }

    bool ECS::isValid(EntityHandle entity) const noexcept {
        return entities_.isValid(entity);
    }
}
