/*
    EntityQuery.cpp

    Implementation of a test for querying the ECS structure.
*/

#include "testing/core/ecs/component/EntityQuery.hpp"
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
        auto component = ecs.get<Component>(handle);
        assert(component->value == value, "Entity component doesn't match expected value");
    }
}

namespace toxico::test {
    TestResult EntityQuery::test() {
        // Create an ECS
        auto core = CoreFactory::create();
        auto& ecs = core->ecs();

        // Create entities.
        std::vector<EntityHandle> entities;
        for (std::size_t i = 0; i < 10; ++i)
            entities.push_back(ecs.create<Position, Velocity>());
        for (std::size_t i = 0; i < 10; ++i)
            entities.push_back(ecs.create<Position>());

        // Query to add velocities together
        for (auto [entity, pos, vel] : ecs.query<Position, Velocity>())
            pos.value += vel.value;

        // Assert value
        for (auto entity : entities) {
            if (ecs.has<Velocity>(entity))
                assertValue<Position>(ecs, entity, Velocity{}.value);
            else
                assertValue<Position>(ecs, entity, Position{}.value);
        }

        // Validate invalid queries don't iterate over any entities
        std::size_t invalid_count = 0;
        for (auto result : ecs.query<Position, Velocity, Health>())
            ++invalid_count;
        assert(invalid_count == 0, "Invalid query iterated over an entity");

        // Validate empty queries iterate over all entities
        std::size_t empty_count = 0;
        for (auto result : ecs.query())
            ++empty_count;
        assert(empty_count = entities.size(), "Empty query did not iterator over every entity");

        return {
            .success = true
        };
    }

    EntityQuery::EntityQuery()
        : Test("Entity Query") {}
}
