/*
    TestResult.hpp

    Declaration of a struct containing test result data.
*/

#pragma once

#include <optional>
#include <string>

namespace toxico::test {
    struct TestResult {
        bool success = false;
        std::optional<std::string> info;
    };
}
