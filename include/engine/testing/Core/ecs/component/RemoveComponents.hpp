/*
    RemoveComponents.hpp

    Declaration of a test for removing components from an ECS entity.
*/

#pragma once

#include "testing/Test.hpp"

namespace toxico::test {
    class RemoveComponents : public Test {
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
        RemoveComponents();
    };
}
