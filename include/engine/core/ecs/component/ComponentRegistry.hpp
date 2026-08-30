/*
    ComponentRegistry.hpp

    Declaration of a component registry.
*/

#pragma once

#include "core/ecs/component/interfaces/IComponentPool.hpp"
#include "core/ecs/component/ComponentId.hpp"
#include "foundation/containers/IndexedList.hpp"
#include "core/concepts/Component.hpp"
#include <functional>
#include <typeindex>
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
        std::size_t size() const noexcept;

    private:
        using StorageFactory = std::function<std::unique_ptr<IComponentPool>()>;

        IndexedList<std::type_index, ComponentId> ids_;
        std::vector<StorageFactory> factories_;
    };
}

#include "core/ecs/component/ComponentRegistry.tpp"
