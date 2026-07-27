/*
    Job.cpp

    Implementation of a job object.
*/

#include "Core/Jobs/Job.hpp"

namespace toxico {
    Job::Job(std::function<void()> task, std::function<void()> on_complete)
        : state_(std::make_shared<JobState>()),
          on_complete_(on_complete),
          task_(task)
    {}

    void Job::execute() {
        if (!state_->canceled)
            task_();

        state_->finished.store(true, std::memory_order_release);

        if (on_complete_)
            on_complete_();
    }

    JobHandle Job::handle() const {
        return JobHandle(state_);
    }
}
