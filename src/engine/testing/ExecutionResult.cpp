/*
    ExecutionResult.cpp

    Implementation of a struct containing test execution data.
*/

#include "testing/ExecutionResult.hpp"

namespace toxico::test {
    std::ostream& operator<<(std::ostream& o, const ExecutionResult& result) {
        o << "Result: " << (result.success ? "Passed" : "Failed") << "\n";
        o << "Time:   " << result.microseconds * 1e-3 << " ms";
        if (result.info)
            o << "\n" << *result.info;

        return o;
    }
}
