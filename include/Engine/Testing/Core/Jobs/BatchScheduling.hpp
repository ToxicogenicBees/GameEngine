/*
    BatchScheduling.hpp

    Declaration of a job batching test.
*/

#pragma once

#include "Testing/Test.hpp"
#include "Foundation/Result.hpp"
#include <string>

namespace toxico::test {
    class BatchScheduling final : public Test {
    public:
        /**
         * @brief Constructor.
         */
        BatchScheduling();

        /**
         * @brief Executes the task.
         * 
         * @return The success state and any additional message about execution.
         */
        Result<std::string, bool> execute() final;
    };
}
