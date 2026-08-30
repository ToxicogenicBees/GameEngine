/*
    AlwaysThrow.hpp

    Declaration of a test that always throws.
*/

#pragma once

#include "testing/Test.hpp"
#include "testing/TestResult.hpp"
#include <string>

namespace toxico::test {
    class AlwaysThrow final : public Test {
    protected:
        /**
         * @brief Executes the test.
         * 
         * @return The test results.
         * 
         * Always throws a std::runtime_error exception.
         */
        TestResult test() final;

    public:
        /**
         * @brief Constructor.
         */
        AlwaysThrow();
    };
}
