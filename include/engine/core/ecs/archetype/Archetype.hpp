/*
    Archetype.hpp

    Declaration of an ECS archetype.
*/

#pragma once

#include "core/ecs/component/interfaces/IComponentPool.hpp"
#include "core/ecs/archetype/ArchetypeEraseResult.hpp"
#include "core/ecs/archetype/ArchetypePlacement.hpp"
#include "core/ecs/component/ComponentRegistry.hpp"
#include "core/ecs/entity/EntityHandle.hpp"
#include "foundation/containers/DenseVector.hpp"
#include "foundation/containers/OwningMap.hpp"
#include "core/ecs/Signature.hpp"

namespace toxico {
    
    class Archetype {
    private:
        OwningMap<ComponentId, IComponentPool> components_;
        DenseVector<EntityHandle> entities_;
        Signature signature_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param component_registry A component registry used for storage requests.
         * @param storage A pre-initialized type set for component storage.
         */
        Archetype(const ComponentRegistry& component_registry, const Signature& signature) noexcept;

        /**
         * @brief Adds an entity to this archetype.
         * 
         * @return The placement in this new entity sits in.
         */
        ArchetypePlacement create(EntityHandle entity) noexcept;

        /**
         * @brief Removes an entity from this archetype.
         * 
         * @param index The entity index being removed.
         * @return Information on any moved entities.
         * 
         * Throws an exception if the row accesses an entity out of bounds.
         */
        ArchetypeEraseResult erase(ArchetypePlacement::index_type row) noexcept;

        /**
         * @brief Gets an entity from this archetype.
         * 
         * @param row The entity row being fetched.
         * @return The entity at this row.
         * 
         * Throws an exception if the row accesses an entity out of bounds.
         */
        EntityHandle getEntity(ArchetypePlacement::index_type row) const;

        /**
         * @brief Gets the component pool for a specific component id.
         * 
         * @param id The component id for the desired component pool.
         * @return The component pool, or nullptr if there is no pool for the given id.
         */
        const IComponentPool* getPool(ComponentId id) const noexcept;
        IComponentPool* getPool(ComponentId id) noexcept;

        /**
         * @brief Gets if this archetype is a superset of a given signature.
         * 
         * @param signature The signature being checked against.
         * @return If this archetype is a superset of the given signature.
         */
        bool contains(const Signature& signature) const;

        /**
         * @brief Gets the signature of this archetype.
         * 
         * @return The signature of this archetype.
         */
        const Signature& signature() const noexcept;

        /**
         * @brief Gets the number of entities in this archetype.
         * 
         * @return The number of entities in this archetype.
         */
        ArchetypePlacement::index_type size() const noexcept;

        /**
         * @brief Gets if the archetype is empty.
         * 
         * @return If the archetype is empty.
         */
        bool empty() const noexcept;
    };
}
