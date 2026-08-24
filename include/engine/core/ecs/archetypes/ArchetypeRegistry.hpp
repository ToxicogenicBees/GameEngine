/*
    ArchetypeRegistry.hpp

    Declaration of an archetype registry.
*/

#pragma once

#include "core/ecs/archetypes/ArchetypePlacement.hpp"
#include "core/ecs/archetypes/Archetype.hpp"
#include "core/ecs/archetypes/Signature.hpp"
#include "core/ecs/components/ComponentRegistry.hpp"
#include "foundation/Context.hpp"
#include <unordered_map>
#include <memory>

namespace toxico {
    class ArchetypeRegistry {
    private:
        std::unordered_map<Signature, std::unique_ptr<Archetype>> archetypes_;
        const ComponentRegistry& component_registry_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param context A context containing the component registry used for indexing.
         * 
         * Throws an exception if the context provided doesn't contain a component registry.
         */
        ArchetypeRegistry(const Context& context);

        /**
         * @brief Gets the archetype with a given signature.
         * 
         * @param signature The desired archetype signature.
         * @return The desired archetype, or nullptr if it doesn't exist.
         */
        const Archetype* get(const Signature& signature) const noexcept;
        Archetype* get(const Signature& signature) noexcept;

        /**
         * @brief Fetches the archetype with a given signature, or
         *        creates one if none were found.
         * 
         * @param signature The desired archetype signature.
         * @return The desired archetype.
         */
        Archetype& fetch(const Signature& signature) noexcept;

        /**
         * @brief Gets if a given archetype exists.
         * 
         * @param signature The signature of the desired archetype.
         * @return If the archetype exists.
         */
        bool contains(const Signature& signature) const noexcept;

        /**
         * @brief Gets the number of unique archetypes in the registry.
         * 
         * @return The number of unique archetypes in the registry.
         */
        size_t size() const;
    };
}
