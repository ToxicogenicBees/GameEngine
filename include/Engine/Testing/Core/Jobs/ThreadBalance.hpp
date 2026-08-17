/*
    ThreadBalance.hpp

    Declaration of a thread balance test.
*/

#pragma once

#include "testing/Test.hpp"
#include "testing/TestResult.hpp"
#include "testing/core/jobs/JobTestConfig.hpp"
#include <string>

namespace toxico::test {
    class ThreadBalance final : public Test {
    private:
        const JobTestConfig CONFIG_;

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
         * 
         * @param config The config for this test
         */
        ThreadBalance(const JobTestConfig& config);
    };
}
