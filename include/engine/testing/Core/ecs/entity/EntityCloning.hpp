/*
    EntityCloning.hpp

    Declaration of a test for cloning an entity.
*/

#pragma once

#include "testing/Test.hpp"

namespace toxico::test {
    class EntityCloning : public Test {
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
        EntityCloning();
    };
}
