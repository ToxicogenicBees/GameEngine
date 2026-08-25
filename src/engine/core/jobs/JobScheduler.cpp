/*
    JobScheduler.cpp

    Implementation of a job scheduler.
*/

#include "core/jobs/JobScheduler.hpp"
#include <algorithm>

namespace {
    std::size_t index(toxico::JobPool pool) {
        return static_cast<std::size_t>(pool);
    }
}

namespace toxico {
    JobScheduler::JobScheduler() {
        // Total available threads (minus the main thread)
        auto remaining_threads = std::thread::hardware_concurrency() - 1;

        // Create a thread pool
        pools_.reserve(index(JobPool::COUNT));
        auto create_pool = [this, &remaining_threads](JobPool pool, std::size_t count) {
            pools_.insert(pools_.begin() + index(pool), std::make_unique<ThreadPool>(count));
            remaining_threads -= count;
        };

        create_pool(JobPool::Background, 1);
        create_pool(JobPool::Frame, std::max(1u, remaining_threads));
    }

    JobHandle JobScheduler::submit(JobPool pool, std::function<void()> task) {
        return pools_[index(pool)]->submit(task);
    }

    JobBatchHandle JobScheduler::submit(JobPool pool, JobBatch batch) {
        std::vector<JobHandle> handles;
        
        while (!batch.empty())
            handles.push_back(submit(pool, batch.pop()));

        return JobBatchHandle(handles.begin(), handles.end());
    }

    std::size_t JobScheduler::threads(JobPool pool) const {
        return pools_[index(pool)]->threads();
    }
}
