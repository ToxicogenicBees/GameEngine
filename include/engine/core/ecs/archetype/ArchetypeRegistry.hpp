/*
    ArchetypeRegistry.hpp

    Declaration of an archetype registry.
*/

#pragma once

#include "core/ecs/component/ComponentRegistry.hpp"
#include "core/ecs/archetype/Archetype.hpp"
#include "core/ecs/archetype/Signature.hpp"
#include <unordered_map>
#include <memory>

namespace toxico {
    class ArchetypeRegistry {
    private:
        using Archetypes = std::unordered_map<Signature, std::unique_ptr<Archetype>>;

        Archetypes archetypes_;
        const ComponentRegistry& component_registry_;

    public:
        using const_iterator = Archetypes::const_iterator;
        using iterator = Archetypes::iterator;

        /**
         * @brief Constructor.
         * 
         * @param components A component registry used for indexing.
         */
        ArchetypeRegistry(const ComponentRegistry& components);

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
        std::size_t size() const;

        /**
         * @brief Gets the desired iterator for this registry's archetypes.
         * 
         * @return The desired iterator.
         */
        const_iterator cbegin() const noexcept;
        const_iterator begin() const noexcept;
        iterator begin() noexcept;
        const_iterator cend() const noexcept;
        const_iterator end() const noexcept;
        iterator end() noexcept;
    };
}
