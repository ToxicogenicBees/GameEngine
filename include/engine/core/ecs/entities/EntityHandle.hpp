/*
    EntityHandle.hpp

    Declaration of a light-weight Entity handle.
*/

#pragma once

#include "foundation/containers/Handle.hpp"
#include "core/ecs/entities/EntityData.hpp"
#include <cstdint>

namespace toxico {
    using EntityHandle = Handle<uint32_t, EntityData>;
}
