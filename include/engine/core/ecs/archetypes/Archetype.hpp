/*
    Archetype.hpp

    Declaration of an ECS archetype.
*/

#pragma once

#include "core/ecs/components/interfaces/IComponentPool.hpp"
#include "core/ecs/archetypes/ArchetypePlacement.hpp"
#include "core/ecs/components/ComponentRegistry.hpp"
#include "core/ecs/entities/EntityHandle.hpp"
#include "foundation/containers/DenseVector.hpp"
#include "core/ecs/archetypes/Signature.hpp"
#include "foundation/Context.hpp"
#include <optional>
#include <iterator>
#include <vector>
#include <memory>

namespace toxico {
    
    class Archetype {
    private:
        struct ComponentStorage {
            ComponentId id;
            std::unique_ptr<IComponentPool> pool;
        };

        std::vector<ComponentStorage> components_;
        DenseVector<EntityHandle> entities_;
        Signature signature_;

    public:
        struct EraseResult {
            std::optional<EntityHandle> moved;
            ArchetypePlacement placement;
        };

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
         */
        Archetype::EraseResult erase(ArchetypePlacement::index_type row) noexcept;

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
    };
}
