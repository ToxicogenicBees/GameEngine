/*
    ECSQueryStorage.hpp

    Declaration of a struct containing ECS query information.
*/

#pragma once

#include "core/ecs/archetype/ArchetypePlacement.hpp"
#include "core/ecs/archetype/ArchetypeRegistry.hpp"
#include "foundation/utility/IterationRange.hpp"
#include "core/ecs/component/ComponentPool.hpp"
#include "core/concepts/Component.hpp"
#include <tuple>

namespace toxico {
    template<Component... Cs>
    struct ECSQueryStorage {
        std::tuple<ComponentPool<Cs>*...> pools;
        ArchetypeRegistry::iterator current;
        ArchetypeRegistry::iterator end;
        ArchetypePlacement::index_type row;
    };
}
