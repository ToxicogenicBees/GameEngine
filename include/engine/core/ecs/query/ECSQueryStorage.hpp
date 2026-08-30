/*
    ECSQueryStorage.hpp

    Declaration of a struct containing ECS query information.
*/

#pragma once

#include "core/ecs/archetype/ArchetypePlacement.hpp"
#include "core/ecs/archetype/ArchetypeRegistry.hpp"
#include "core/ecs/component/ComponentPool.hpp"
#include "core/concepts/Component.hpp"
#include <tuple>

namespace toxico {
    template<Component... Components>
    struct ECSQueryStorage {
        std::tuple<ComponentPool<Components>*...> pools;
        ArchetypeRegistry::iterator archetype_iter;
        ArchetypePlacement::index_type row;
    };
}
