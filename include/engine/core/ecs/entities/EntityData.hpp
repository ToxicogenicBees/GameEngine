/*
    EntityData.hpp

    Declaration of a struct containing ECS meta-data for an entity.
*/

#pragma once

#include "core/ecs/archetypes/ArchetypePlacement.hpp"

namespace toxico {
    struct EntityData {
        ArchetypePlacement placement;
    };
}
