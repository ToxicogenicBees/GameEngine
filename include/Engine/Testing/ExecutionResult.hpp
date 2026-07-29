/*
    ExecutionResult.hpp

    Declaration of a struct containing test execution data.
*/

#pragma once

#include <string>

namespace toxico::test {
    struct ExecutionResult {
        bool success = false;
        std::string info = "N/A";
        double microseconds = 0;
    };
}
