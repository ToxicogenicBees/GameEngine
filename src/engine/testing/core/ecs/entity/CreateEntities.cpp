/*
    CreateEntities.cpp

    Implementation of a test for creating ECS entities.
*/

#include "testing/core/ecs/entity/CreateEntities.hpp"
#include "core/utility/random/Guid.hpp"
#include "foundation/math/Vector.hpp"
#include "core/CoreFactory.hpp"

namespace {
    struct Velocity { toxico::Vector3 value = toxico::Vector3::one(); };
    struct Position { toxico::Vector3 value = toxico::Vector3::zero(); };
    struct Health { int value = 100; };

    template<typename Component, typename Value>
    void assertValue(toxico::ECS& ecs, toxico::EntityHandle handle, Value value) {
        auto component = ecs.get<Component>(handle);
        if (component->value != value)
            throw std::runtime_error("Entity component doesn't match expected value");
    }
}

namespace toxico::test {
    TestResult CreateEntities::test() {
        // Create an ECS
        auto core = CoreFactory::create();
        auto& ecs = core->ecs();

        // Create entities.
        const Position POSITION{Vector3::xAxis()};
        const Velocity VELOCITY{Vector3::zAxis()};
        const Health HEALTH{50};
        auto e_vp = ecs.create<Velocity, Position>();
        auto e_pv = ecs.create<Position, Velocity>(POSITION, VELOCITY);
        auto e_h = ecs.create<Health>(HEALTH);

        // Verify values
        assertValue<Velocity>(ecs, e_vp, Velocity{}.value);
        assertValue<Position>(ecs, e_vp, Position{}.value);
        assertValue<Velocity>(ecs, e_pv, VELOCITY.value);
        assertValue<Position>(ecs, e_pv, POSITION.value);
        assertValue<Health>(ecs, e_h, HEALTH.value);

        return TestResult {
            .success = true
        };
    }

    CreateEntities::CreateEntities()
        : Test("Create Entites") {}
}
