/*
    CreateEntities.hpp

    Declaration of a test for creating ECS entities.
*/

#pragma once

#include "testing/Test.hpp"

namespace toxico::test {
    class CreateEntities : public Test {
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
        CreateEntities();
    };
}
