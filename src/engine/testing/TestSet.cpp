/*
    TestSet.cpp

    Implementation of a set of engine tests.
*/

#include "testing/TestSet.hpp"
#include <format>

namespace toxico::test {
    TestResult TestSet::test() {
        // Attempt to run all the tests
        std::string failed_name;
        bool all_pass = true;
        for (auto& test : tests_) {
            // Run tests, breaking on failure
            auto result = test.execute();
            if (!result.success) {
                failed_name = test.name();
                all_pass = false;
                break;
            }
        }

        // Test failed
        if (!all_pass) {
            return TestResult {
                .success = false,
                .info = std::format("Failed: {}", failed_name)
            };
        }
        
        // Test passed
        return TestResult{
            .success = true
        };
    }

    TestSet::TestSet(const std::string& name) noexcept
        : Test(name) {}
}
