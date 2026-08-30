/*
    EntityQuery.hpp

    Declaration of a test for querying the ECS structure.
*/

#pragma once

#include "testing/Test.hpp"

namespace toxico::test {
    class EntityQuery : public Test {
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
        EntityQuery();
    };
}
