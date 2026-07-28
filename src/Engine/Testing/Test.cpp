/*
    Test.cpp

    Implementation of an abstract engine debug test.
*/

#include "Testing/Test.hpp"

namespace toxico::test {
    Test::Test(const std::string& name)
        : NAME_(name) {}

    const std::string& Test::name() const {
        return NAME_;
    }

    std::ostream& operator<<(std::ostream& o, Test& test) {
        // Execute the test
        auto result = test.execute();

        // Output test result
        o << "Test: " << test.name() << "\n";
        o << "Result: " << (result.has_value() ? "Failed" : "Passed");

        // Output any messages
        if (result)
            o << "\n" << *result;

        return o;
    }
}