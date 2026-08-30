/*
    Test.cpp

    Implementation of an abstract engine debug test.
*/

#include "core/utility/Timer.hpp"
#include "testing/Test.hpp"

namespace toxico::test {
    Test::Test(const std::string& name)
        : NAME_(name) {}

    const std::string& Test::name() const {
        return NAME_;
    }

    ExecutionResult Test::execute() noexcept {
        Timer timer;

        TestResult result;
        try {
            result = test();
        }
        catch (std::exception& e) {
            result = {
                .success = false,
                .info = e.what()
            };
        }

        return {
            .success = result.success,
            .info = result.info,
            .microseconds = timer.microseconds()
        };
    }

    std::ostream& operator<<(std::ostream& o, Test& test) {
        // Execute the test
        auto result = test.execute();

        // Output test result
        o << "Test:   " << test.name() << "\n";
        o << result;

        return o;
    }
}