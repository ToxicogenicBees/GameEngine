/*
    AlwaysPass.hpp

    Declaration of a test that always passes.
*/

#pragma once

#include "testing/Test.hpp"
#include "testing/TestResult.hpp"
#include <string>

namespace toxico::test {
    class AlwaysPass final : public Test {
    protected:
        /**
         * @brief Executes the test.
         * 
         * @return The test results.
         */
        TestResult test() noexcept final;

    public:
        /**
         * @brief Constructor.
         */
        AlwaysPass();
    };
}
