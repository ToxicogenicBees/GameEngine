/*
    AddComponents.hpp

    Declaration of a test for adding components to an ECS entity.
*/

#pragma once

#include "testing/Test.hpp"

namespace toxico::test {
    class AddComponents : public Test {
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
        AddComponents();
    };
}
