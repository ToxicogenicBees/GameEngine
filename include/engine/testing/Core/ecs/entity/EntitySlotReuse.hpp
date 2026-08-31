/*
    EntitySlotReuse.hpp

    Declaration of a test for reusing ECS entity slots.
*/

#pragma once

#include "testing/Test.hpp"

namespace toxico::test {
    class EntitySlotReuse : public Test {
    protected:
        /**
         * @brief Executes the test.
         * 
         * @return The test results.
         */
        TestResult test() final;

    public:
        /**
         * @brief Constructor.
         */
        EntitySlotReuse();
    };
}
