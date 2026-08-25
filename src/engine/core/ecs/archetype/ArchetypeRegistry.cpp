/*
    ArchetypeRegistry.cpp

    Implementation of an archetype registry.
*/

#include "core/ecs/archetype/ArchetypeRegistry.hpp"

namespace toxico {
    ArchetypeRegistry::ArchetypeRegistry(const ComponentRegistry& components)
        : component_registry_(components) {}

    const Archetype* ArchetypeRegistry::get(const Signature& signature) const noexcept {
        auto it = archetypes_.find(signature);

        if (it == archetypes_.end())
            return nullptr;

        return it->second.get();
    }

    Archetype* ArchetypeRegistry::get(const Signature& signature) noexcept {
        auto it = archetypes_.find(signature);

        if (it == archetypes_.end())
            return nullptr;

        return it->second.get();
    }

    Archetype& ArchetypeRegistry::fetch(const Signature& signature) noexcept {
        if (!archetypes_.contains(signature))
            archetypes_.emplace(signature, std::make_unique<Archetype>(component_registry_, signature));

        return *archetypes_[signature].get();
    }

    bool ArchetypeRegistry::contains(const Signature& signature) const noexcept {
        return archetypes_.contains(signature);
    }

    std::size_t ArchetypeRegistry::size() const {
        return archetypes_.size();
    }

    ArchetypeRegistry::const_iterator ArchetypeRegistry::cbegin() const noexcept {
        return archetypes_.cbegin();
    }

    ArchetypeRegistry::const_iterator ArchetypeRegistry::begin() const noexcept {
        return archetypes_.begin();
    }

    ArchetypeRegistry::iterator ArchetypeRegistry::begin() noexcept {
        return archetypes_.begin();
    }

    ArchetypeRegistry::const_iterator ArchetypeRegistry::cend() const noexcept {
        return archetypes_.cend();
    }

    ArchetypeRegistry::const_iterator ArchetypeRegistry::end() const noexcept {
        return archetypes_.end();
    }

    ArchetypeRegistry::iterator ArchetypeRegistry::end() noexcept {
        return archetypes_.end();
    }
}
