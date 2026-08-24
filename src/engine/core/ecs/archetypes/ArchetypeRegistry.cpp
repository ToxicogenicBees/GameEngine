/*
    ArchetypeRegistry.cpp

    Implementation of an archetype registry.
*/

#include "core/ecs/archetypes/ArchetypeRegistry.hpp"

namespace toxico {
    ArchetypeRegistry::ArchetypeRegistry(const Context& context)
        : component_registry_(context.get<ComponentRegistry>()) {}

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

    size_t ArchetypeRegistry::size() const {
        return archetypes_.size();
    }
}
