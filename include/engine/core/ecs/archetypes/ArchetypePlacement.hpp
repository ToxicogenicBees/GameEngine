/*
    ArchetypePlacement.hpp

    Declaration of a struct containing archetype placement information for an entity.
*/

#pragma once

#include "core/ecs/archetypes/Signature.hpp"
#include <cstdint>

namespace toxico {
    struct ArchetypePlacement {
        using index_type = uint32_t;

        Signature signature;
        index_type row;
    };
}
