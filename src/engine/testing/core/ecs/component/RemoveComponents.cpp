/*
    RemoveComponents.cpp

    Implementation of a test for removing components from an ECS entity.
*/

#include "testing/core/ecs/component/RemoveComponents.hpp"
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

    template<typename Component, typename Value>
    void assertValue(toxico::ECS& ecs, toxico::EntityHandle handle, Value value) {
        auto* component = ecs.get<Component>(handle);
        assert(component, "Failed to fetch component");
        assert(component->value == value, "Entity component doesn't match expected value");
    }

    template<typename... Components>
    void assertCount(toxico::ECS& ecs, std::size_t count) {
        std::size_t queried = 0;
        for (auto _ : ecs.query<Components...>())
            ++queried;

        assert(queried == count, "Component count doesn't match expected value");
    }

    template<typename... Components>
    void assertContains(toxico::ECS& ecs, toxico::EntityHandle expected) {
        bool found = false;
        for (auto result : ecs.query<Components...>()) {
            if (std::get<0>(result) == expected) {
                found = true;
                break;
            }
        }

        assert(found, "Entity not found in query");
    }
}

namespace toxico::test {
    TestResult RemoveComponents::test() {
        // Create an ECS
        auto core = CoreFactory::create();
        auto& ecs = core->ecs();

        // Create entities.
        auto e1 = ecs.create<Position, Velocity, Health>({Vector3::xAxis()}, {Vector3::zero()}, {100});
        auto e2 = ecs.create<Position, Velocity, Health>({Vector3::yAxis()}, {Vector3::zero()}, {100});
        auto e3 = ecs.create<Position, Velocity, Health>({Vector3::zAxis()}, {Vector3::zero()}, {100});

        // Remove velocity from e2
        ecs.remove<Velocity>(e2);

        // Validate handles
        assert(ecs.isValid(e1), "Failed to validate E1 (unmodified)");
        assert(ecs.isValid(e2), "Failed to validate E2 (modified)");
        assert(ecs.isValid(e3), "Failed to validate E3 (unmodified)");

        // Validate component counts
        assertCount<Position, Velocity, Health>(ecs, 2);
        assertCount<Position, Health>(ecs, 3);

        // Validate archetype expectations
        assertContains<Position, Velocity, Health>(ecs, e1);
        assertContains<Position, Health>(ecs, e2);
        assertContains<Position, Velocity, Health>(ecs, e3);

        // Validate positions
        assertValue<Position>(ecs, e1, Vector3::xAxis());
        assertValue<Position>(ecs, e2, Vector3::yAxis());
        assertValue<Position>(ecs, e3, Vector3::zAxis());

        // Removed health from e3
        ecs.remove<Health>(e3);

        // Validate handles
        assert(ecs.isValid(e1), "Failed to validate E1 (unmodified)");
        assert(ecs.isValid(e2), "Failed to validate E2 (modified)");
        assert(ecs.isValid(e3), "Failed to validate E3 (modified)");

        // Validate component counts
        assertCount<Position, Health>(ecs, 2);
        assertCount<Position, Velocity>(ecs, 2);
        assertCount<Position, Velocity, Health>(ecs, 1);

        // Validate archetype expectations
        assertContains<Position, Velocity, Health>(ecs, e1);
        assertContains<Position, Health>(ecs, e2);
        assertContains<Position, Velocity>(ecs, e3);

        // Validate positions
        assertValue<Position>(ecs, e1, Vector3::xAxis());
        assertValue<Position>(ecs, e2, Vector3::yAxis());
        assertValue<Position>(ecs, e3, Vector3::zAxis());

        // Remove health and velocity from e1
        ecs.remove<Velocity>(e1);
        ecs.remove<Health>(e1);

        // Validate component counts
        assertCount<Position, Health>(ecs, 1);
        assertCount<Position, Velocity>(ecs, 1);
        assertCount<Position>(ecs, 3);

        // Validate archetype expectations
        assertContains<Position>(ecs, e1);
        assertContains<Position, Health>(ecs, e2);
        assertContains<Position, Velocity>(ecs, e3);

        // Validate handles
        assert(ecs.isValid(e1), "Failed to validate E1 (modified)");
        assert(ecs.isValid(e2), "Failed to validate E2 (modified)");
        assert(ecs.isValid(e3), "Failed to validate E3 (modified)");

        // Validate positions
        assertValue<Position>(ecs, e1, Vector3::xAxis());
        assertValue<Position>(ecs, e2, Vector3::yAxis());
        assertValue<Position>(ecs, e3, Vector3::zAxis());

        return TestResult{
            .success = true
        };
    }

    RemoveComponents::RemoveComponents()
        : Test("Remove Components") {}
}
