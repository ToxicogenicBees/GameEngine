/*
    ECSUnitTest.cpp

    Implementation of a unit test for the ECS structure.
*/

#include "testing/core/ecs/ECSUnitTest.hpp"
#include "testing/core/ecs/component/RemoveComponents.hpp"
#include "testing/core/ecs/component/AddComponents.hpp"
#include "testing/core/ecs/component/EntityQuery.hpp"
#include "testing/core/ecs/entity/AccessAfterDestroy.hpp"
#include "testing/core/ecs/entity/CreateEntities.hpp"

namespace toxico::test {
    ECSUnitTest::ECSUnitTest() 
        : TestSet("ECS Unit Test")
    {
        // Entity creation
        add<CreateEntities>();

        // Component manipulation
        add<EntityQuery>();
        add<AddComponents>();
        add<RemoveComponents>();

        // Entity manipulation
        add<AccessAfterDestroy>();
        // @TODO: Entity cloning
    }
}
