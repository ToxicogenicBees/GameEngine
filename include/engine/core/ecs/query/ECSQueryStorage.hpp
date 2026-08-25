/*
    ECSQueryStorage.hpp

    Declaration of a struct containing ECS query information.
*/

#pragma once

#include "core/ecs/components/concepts/Component.hpp"
#include "core/ecs/archetypes/ArchetypePlacement.hpp"
#include "core/ecs/archetypes/ArchetypeRegistry.hpp"
#include "core/ecs/components/ComponentPool.hpp"
#include "core/ecs/archetypes/Signature.hpp"
#include <tuple>

namespace toxico {
    template<Component... Components>
    struct ECSQueryStorage {
        std::tuple<ComponentPool<Components>*...> pools;
        ArchetypeRegistry::iterator archetype_iter;
        ArchetypePlacement::index_type row;
    };
}
