/*
    ComponentRegistry.hpp

    Declaration of a component registry.
*/

#pragma once

#include "core/ecs/components/concepts/Component.hpp"
#include "core/ecs/components/interfaces/IComponentPool.hpp"
#include "core/ecs/components/ComponentId.hpp"
#include "foundation/containers/IndexTable.hpp"
#include <functional>
#include <typeindex>
#include <cstdint>
#include <memory>

namespace toxico {
    class ComponentRegistry {
    public:
        /**
         * @brief Adds a component to the registry.
         */
        template<Component C>
        void insert();

        /**
         * @brief Gets the id of the desired component type.
         * 
         * @return The id of the desired component type.
         * 
         * Throws an exception if the type isn't registered into the registry.
         */
        template<Component C>
        ComponentId getId() const;

        /**
         * @brief Gets the id of the desired component type.
         * 
         * @param type_index The type index of the desired component type.
         * @return The id of the desired component type.
         * 
         * Throws an exception if the type isn't registered into the registry.
         */
        ComponentId getId(const std::type_index& type_index) const;

        /**
         * @brief Gets if a given component type is registered.
         * 
         * @return If the type is registered.
         */
        template<Component C>
        bool hasId() const noexcept;

        /**
         * @brief Gets if a given component type is registered.
         * 
         * @param type_index The type index of the desired component type.
         * @return If the type is registered.
         */
        bool hasId(const std::type_index& type_index) const noexcept;

        /**
         * @brief Creates a storage container for components of a certain type.
         * 
         * @param id The id of the desired component type.
         * @return A storage container of the desired type.
         * 
         * Throws an exception if the type isn't registered into the registry.
         */
        std::unique_ptr<IComponentPool> createStorage(ComponentId id) const;

        /**
         * @brief Gets the number of unique components registered in the registry.
         * 
         * @return The number of unique components registered in the registry.
         */
        size_t size() const noexcept;

    private:
        using StorageFactory = std::function<std::unique_ptr<IComponentPool>()>;

        IndexTable<std::type_index, ComponentId> ids_;
        std::vector<StorageFactory> factories_;
    };
}

#include "core/ecs/components/ComponentRegistry.tpp"
