/*
    Test.cpp

    Implementation of an abstract engine debug test.
*/

#include "Core/Utility/Timer.hpp"
#include "Testing/Test.hpp"

namespace toxico::test {
    Test::Test(const std::string& name)
        : NAME_(name) {}

    const std::string& Test::name() const {
        return NAME_;
    }

    ExecutionResult Test::execute() {
        Timer timer;

        auto result = test();

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
        o << "Result: " << (result.success ? "Passed" : "Failed") << "\n";
        o << "Info:   " << result.info << "\n";
        o << "Time:   " << result.microseconds * 1e-3 << " ms";

        return o;
    }
}