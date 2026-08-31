/*
    EntityCloning.hpp

    Implementation of a test for cloning an entity.
*/

#include "testing/core/ecs/entity/EntityCloning.hpp"
#include "foundation/math/Vector.hpp"
#include "core/CoreFactory.hpp"

namespace {
    struct Position { toxico::Vector3 value = toxico::Vector3::zero(); };
    struct Velocity { toxico::Vector3 value = toxico::Vector3::zero(); };
    struct Health { int value = 100; };

    void assert(bool value, const std::string& message) {
        if (!value)
            throw std::runtime_error(message);
    }
}

namespace toxico::test {
    TestResult EntityCloning::test() {
        // Create an ECS
        auto core = CoreFactory::create();
        auto& ecs = core->ecs();

        // Create a set of entites with unique components
        auto e1 = ecs.create<Position, Velocity, Health>({Vector3::xAxis()}, {Vector3::xAxis()}, {50});
        auto e2 = ecs.create<Position, Velocity, Health>({Vector3::yAxis()}, {Vector3::yAxis()}, {100});
        auto e3 = ecs.create<Position, Velocity, Health>({Vector3::zAxis()}, {Vector3::zAxis()}, {150});

        // Clone e2
        auto clone = ecs.clone(e2);

        // Verify that e4 is a new entity
        auto assert_different = [&clone](EntityHandle e) {
            assert(clone.index() != e.index(), "Clone is not a unique and new entity");
        };
        assert_different(e1);
        assert_different(e2);
        assert_different(e3);

        // Verify that e4 has a copy of e2's components
        assert(ecs.get<Position>(e2)->value == ecs.get<Position>(clone)->value, "Position doesn't match");
        assert(ecs.get<Velocity>(e2)->value == ecs.get<Velocity>(clone)->value, "Velocity doesn't match");
        assert(ecs.get<Health>(e2)->value == ecs.get<Health>(clone)->value, "Health doesn't match");

        // Destroy e2 and attempt to clone it
        ecs.destroy(e2);
        auto invalid_clone = ecs.clone(e2);

        // Validate that this clone is the same as e2
        assert(!ecs.isValid(invalid_clone), "Cloning an invalid entity returned a valid handle");

        return TestResult {
            .success = true
        };
    }

    EntityCloning::EntityCloning()
        : Test("Entity Cloning") {}
}
