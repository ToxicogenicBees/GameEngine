/*
    AlwaysThrow.cpp

    Implementation of a test that always passes.
*/

#include "testing/misc/AlwaysThrow.hpp"
#include <stdexcept>

namespace toxico::test {
    TestResult AlwaysThrow::test() {
        throw std::runtime_error("This test always throws");
        return {};
    }

    AlwaysThrow::AlwaysThrow()
        : Test("Always Throw") {}
}
