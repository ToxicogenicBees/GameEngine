/*
    ArchetypeEraseResult.hpp

    Declaration of a struct containing erasure information for an archetype.
*/

#pragma once

#include "core/ecs/archetype/ArchetypePlacement.hpp"
#include "core/ecs/entity/EntityHandle.hpp"
#include <optional>

namespace toxico {
    struct ArchetypeEraseResult {
        std::optional<EntityHandle> moved;
        ArchetypePlacement placement;
    };
}
