/*
    AccessAfterDestroy.hpp

    Declaration of a test for validating that an ECS entity's components cannot be accessed after destruction.
*/

#pragma once

#include "testing/Test.hpp"

namespace toxico::test {
    class AccessAfterDestroy : public Test {
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
        AccessAfterDestroy();
    };
}
