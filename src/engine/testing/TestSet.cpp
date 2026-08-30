/*
    TestSet.cpp

    Implementation of a set of engine tests.
*/

#include "testing/TestSet.hpp"
#include <format>

namespace toxico::test {
    TestResult TestSet::test() {
        // Attempt to run all the tests
        std::vector<std::string> successes;
        std::string failed;
        bool all_pass = true;
        for (auto& test : tests_) {
            // Run test and check for success
            auto result = test->execute();
            if (result.success) {
                successes.push_back(test->name());
                continue;
            }

            // Test failed, break
            all_pass = false;
            failed = test->name();
            break;
        }

        // Form info
        std::string info;
        if (!successes.empty()) {
            info += "Passed: ";
            for (const auto& name : successes) {
                info += name;
                if (name != successes.back())
                    info += ", ";
            }
        }
        
        if (!all_pass)
            info += std::format("{}Failed: {}", (successes.empty() ? "" : "\n"), failed);

        return TestResult{
            .success = all_pass,
            .info = info
        };
    }

    TestSet::TestSet(const std::string& name) noexcept
        : Test(name) {}
}
