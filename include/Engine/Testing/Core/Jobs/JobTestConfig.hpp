/*
    JobTestConfig.hpp

    Declaration of a struct containing job testing information.
*/

#pragma once

#include "Core/Jobs/JobScheduler.hpp"
#include <functional>
#include <cstdint>

namespace toxico::test {
    struct JobTestConfig {
        JobPool pool = JobPool::Frame;
        std::size_t job_count = 1000;
        std::size_t yield_ms = 1;
    };
}
