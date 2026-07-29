/*
    BatchScheduling.hpp

    Declaration of a job batching test.
*/

#pragma once

#include "Testing/Test.hpp"
#include "Testing/TestResult.hpp"
#include "Testing/Core/Jobs/JobTestConfig.hpp"
#include <string>

namespace toxico::test {
    class BatchScheduling final : public Test {
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
        BatchScheduling(const JobTestConfig& config);
    };
}
