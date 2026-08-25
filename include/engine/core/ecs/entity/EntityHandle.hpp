/*
    EntityHandle.hpp

    Declaration of a light-weight Entity handle.
*/

#pragma once

#include "core/ecs/archetype/ArchetypePlacement.hpp"
#include "foundation/containers/Handle.hpp"
#include "core/ecs/entity/EntityData.hpp"
#include <cstdint>

namespace toxico {
    using EntityHandle = Handle<ArchetypePlacement::index_type, EntityData>;
}
