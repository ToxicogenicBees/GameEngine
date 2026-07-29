/*
    JobState.hpp

    Declaration of a simple job state struct.
*/

#pragma once

#include "Foundation/Threading/Fence.hpp"
#include <atomic>

namespace toxico {
    struct JobState {
        std::atomic<bool> finished = false;
        std::atomic<bool> canceled = false;
        Fence processing;
    };
}
