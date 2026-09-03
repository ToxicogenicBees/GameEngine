/*
    ComponentRegistry.hpp

    Declaration of a component registry.
*/

#pragma once

#include "core/ecs/component/interfaces/IComponentPool.hpp"
#include "core/ecs/Signature.hpp"
#include "core/ecs/component/ComponentId.hpp"
#include "foundation/containers/IndexedList.hpp"
#include "core/concepts/Component.hpp"
#include <functional>
#include <typeindex>
#include <optional>
#include <memory>

namespace toxico {
    class ComponentRegistry {
    public:
        /**
         * @brief Inserts the desired component into the registry.
         * 
         * @return The id the component maps to.
         */
        template<Component C>
        ComponentId insert();

        /**
         * @brief Finds the id for the desired component.
         * 
         * @return The resulting id.
         * 
         * Throws an exception if the id doesn't exist for this component type.
         */
        template<Component C>
        ComponentId get() const;

        /**
         * @brief Finds the id for the desired component.
         * 
         * @param type The type index for the desired component type.
         * @return The resulting id.
         * 
         * Throws an exception if the id doesn't exist for this component type.
         */
        ComponentId get(const std::type_index& type) const;

        /**
         * @brief Finds the id for the desired component.
         * 
         * @return The resulting id, or std::nullopt if the type hasn't been registered.
         */
        template<Component C>
        std::optional<ComponentId> find() const noexcept;

        /**
         * @brief Finds the id for the desired component.
         * 
         * @param type The type index for the desired component type.
         * @return The resulting id, or std::nullopt if the type hasn't been registered.
         */
        std::optional<ComponentId> find(const std::type_index& type) const noexcept;

        /**
         * @brief Creates a signature for the given set of components.
         * 
         * @return The signature for this set of components.
         */
        template<Component... Cs>
        Signature createSignature();

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
