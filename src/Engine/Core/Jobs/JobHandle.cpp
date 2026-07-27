/*
    JobHandle.cpp

    Implementation of a job handle.
*/

#include "Core/Jobs/JobHandle.hpp"
#include <thread>

namespace toxico {
    JobHandle::JobHandle(std::shared_ptr<JobState> state)
        : state_(state) {}

    bool JobHandle::finished() const {
        return state_->finished;
    }

    bool JobHandle::cancelled() const {
        return state_->canceled;
    }

    void JobHandle::cancel() {
        state_->canceled = true;
    }

    void JobHandle::wait() const {
        // @TODO: Replace with conditional-variable-based waiting
        
        while (!state_->finished.load(std::memory_order_acquire))
            std::this_thread::yield();
    }
}
