/*
    JobQueue.cpp

    Implementation of a thread-safe job queue.
*/

#include "Core/Jobs/JobQueue.hpp"

namespace toxico {
    JobHandle JobQueue::push(std::function<void()> task, std::function<void()> on_complete) {
        Job job(task, on_complete);
        auto handle = job.handle();

        {
            std::lock_guard lock(mutex_);
            jobs_.push(std::move(job));
        }

        condition_.notify_one();

        return handle;
    }

    std::optional<Job> JobQueue::pop(std::stop_token stop) {
        std::unique_lock lock(mutex_);

        condition_.wait(lock, stop, [this] {
            return stopped_ || !jobs_.empty();
        });

        if (stop.stop_requested())
            return std::nullopt;

        if (jobs_.empty())
            return std::nullopt;

        std::optional<Job> job = std::move(jobs_.front());
        jobs_.pop();

        return job;
    }
    
    void JobQueue::stop() {
        {
            std::lock_guard lock(mutex_);
            stopped_ = true;
        }

        condition_.notify_all();
    }

    bool JobQueue::stopped() const {
        std::unique_lock lock(mutex_);

        return stopped_;
    }

    std::size_t JobQueue::size() const {
        std::unique_lock lock(mutex_);

        return jobs_.size();
    }

    bool JobQueue::empty() const {
        std::unique_lock lock(mutex_);

        return jobs_.empty();
    }

    JobQueue::~JobQueue() {
        stop();
    }
}
