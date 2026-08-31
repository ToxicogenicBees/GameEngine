/*
    AccessAfterDestroy.cpp

    Implementation of a test for validating that an ECS entity's components cannot be accessed after destruction.
*/

#include "testing/core/ecs/entity/AccessAfterDestroy.hpp"
#include "core/utility/random/Guid.hpp"
#include "foundation/math/Vector.hpp"
#include "core/CoreFactory.hpp"

namespace {
    struct Velocity { toxico::Vector3 value = toxico::Vector3::one(); };
    struct Position { toxico::Vector3 value = toxico::Vector3::zero(); };
    struct Health { int value = 100; };

    void assert(bool value, const std::string& message) {
        if (!value)
            throw std::runtime_error(message);
    }
}

namespace toxico::test {
    TestResult AccessAfterDestroy::test() {
        // Create an ECS
        auto core = CoreFactory::create();
        auto& ecs = core->ecs();

        // Create an entity.
        auto entity = ecs.create<Position, Velocity, Health>();

        // Destroy the entity
        ecs.destroy(entity);

        // Assert that all access to this handle is now gone.
        assert(!ecs.isValid(entity), "Entity should be marked as invalid");
        assert(!ecs.get<Position>(entity), "Component access for invalid entity should be null");
        assert(!ecs.get<Velocity>(entity), "Component access for invalid entity should be null");
        assert(!ecs.get<Health>(entity), "Component access for invalid entity should be null");

        // Ensure double-erasure does not throw an error
        ecs.destroy(entity);

        return {
            .success = true
        };
    }

    AccessAfterDestroy::AccessAfterDestroy()
        : Test("Access After Destroy") {}
}
