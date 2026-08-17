/*
    JobTestConfig.hpp

    Declaration of a struct containing job testing information.
*/

#pragma once

#include "core/jobs/JobScheduler.hpp"
#include <functional>
#include <cstdint>

namespace toxico::test {
    struct JobTestConfig {
        JobPool pool = JobPool::Frame;
        size_t job_count = 1000;
        size_t yield_ms = 1;
    };
}
