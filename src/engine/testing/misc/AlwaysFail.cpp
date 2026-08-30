/*
    AlwaysFail.cpp

    Implementation of a test that always fails.
*/

#include "testing/misc/AlwaysFail.hpp"

namespace toxico::test {
    TestResult AlwaysFail::test() noexcept {
        return TestResult {
            .success = false,
            .info = "This test always fails"
        };
    }

    AlwaysFail::AlwaysFail()
        : Test("Always Fail") {}
}
