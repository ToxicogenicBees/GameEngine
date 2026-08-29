/*
    ECSQueryContext.hpp

    Declaration of a context holding information for ECS queries.
*/

#pragma once

#include "foundation/utility/Context.hpp"
#include "core/ecs/archetype/ArchetypeRegistry.hpp"
#include "core/ecs/component/ComponentRegistry.hpp"

namespace toxico {
    // Context holding an architype and a component registry
    using ECSQueryContext = Context<ArchetypeRegistry, ComponentRegistry>;
}