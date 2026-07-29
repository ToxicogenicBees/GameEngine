/*
    TestResult.hpp

    Declaration of a struct containing test result data.
*/

#pragma once

#include <string>

namespace toxico::test {
    struct TestResult {
        bool success = false;
        std::string info = "N/A";
    };
}
