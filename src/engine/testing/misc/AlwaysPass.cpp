/*
    AlwaysPass.cpp

    Implementation of a test that always passes.
*/

#include "testing/misc/AlwaysPass.hpp"

namespace toxico::test {
    TestResult AlwaysPass::test() noexcept {
        return TestResult {
            .success = true,
            .info = "This test always passes"
        };
    }

    AlwaysPass::AlwaysPass()
        : Test("Always Pass") {}
}
