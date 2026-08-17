/*
    JobScheduler.hpp

    Declaration of a job scheduler.
*/

#pragma once

#include "core/interfaces/ICoreModule.hpp"
#include "core/jobs/threading/ThreadPool.hpp"
#include "core/jobs/batching/JobBatchHandle.hpp"
#include "core/jobs/batching/JobBatch.hpp"
#include "core/jobs/JobHandle.hpp"
#include <functional>
#include <vector>
#include <memory>

namespace toxico {
    enum class JobPool {
        Background,
        Frame,

        COUNT,
    };

    class JobScheduler : public ICoreModule {
    private:
        std::vector<std::unique_ptr<ThreadPool>> pools_;

    public:
        /**
         * @brief Constructor.
         */
        JobScheduler();

        /**
         * @brief Submit a job to the background pool.
         * 
         * @param pool The pool being submitted to.
         * @param task The task being submitted.
         * @return A handle for the submitted job.
         */
        JobHandle submit(JobPool pool, std::function<void()> task);

        /**
         * @brief Submit a job batch to the background pool.
         * 
         * @param pool The pool being submitted to.
         * @param batch The job batch being submitted.
         * @return A handle for the submitted job.
         */
        JobBatchHandle submit(JobPool pool, JobBatch batch);

        /**
         * @brief Gets the number of threads in the specified pool.
         * 
         * @param pool The pool being checked.
         * @return The number of threads in the specified pool.
         */
        size_t threads(JobPool pool) const;
    };
}
