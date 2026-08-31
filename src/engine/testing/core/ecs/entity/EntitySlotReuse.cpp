/*
    EntitySlotReuse.cpp

    Implementation of a test for creating ECS entities.
*/

#include "testing/core/ecs/entity/EntitySlotReuse.hpp"
#include "foundation/math/Vector.hpp"
#include "core/CoreFactory.hpp"

namespace {
    struct Position { toxico::Vector3 value = toxico::Vector3::one(); };

    void assert(bool value, const std::string& message) {
        if (!value)
            throw std::runtime_error(message);
    }
}

namespace toxico::test {
    TestResult EntitySlotReuse::test() {
        // Create an ECS
        auto core = CoreFactory::create();
        auto& ecs = core->ecs();

        // Reuse entity slot 0 three times
        auto e1 = ecs.create<Position>({Vector3::xAxis()});
        ecs.destroy(e1);
        auto e2 = ecs.create<Position>({Vector3::yAxis()});
        ecs.destroy(e2);
        auto e3 = ecs.create<Position>({Vector3::zAxis()});

        // Verify that only e3 is valid
        assert(!ecs.isValid(e1), "Entity 1 should be invalid");
        assert(!ecs.isValid(e2), "Entity 2 should be invalid");
        assert(ecs.isValid(e3), "Entity 3 should be valid");

        // Verify that the slot is being reused
        assert(e1.index() == e3.index(), "Entity 1 and 3 do not share the same index");
        assert(e2.index() == e3.index(), "Entity 2 and 3 do not share the same index");

        // Verify that the generations are different
        assert(e1.generation() != e2.generation(), "Entity 1 and 2 share the same generation");
        assert(e2.generation() != e3.generation(), "Entity 2 and 3 share the same generation");
        assert(e1.generation() != e3.generation(), "Entity 1 and 3 share the same generation");

        return TestResult {
            .success = true
        };
    }

    EntitySlotReuse::EntitySlotReuse()
        : Test("Entity Slot Reuse") {}
}
