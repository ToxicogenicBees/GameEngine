/*
    JobScheduler.hpp

    Declaration of a job scheduler.
*/

#pragma once

#include "Core/Jobs/ThreadPool.hpp"
#include "Core/Jobs/JobHandle.hpp"
#include <functional>
#include <unordered_map>

namespace toxico {
    enum class JobPool {
        Background,
        Frame,

        COUNT,
    };

    class JobScheduler {
    private:
        std::vector<ThreadPool> pools_;

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
         * @brief Waits for all jobs in the pool to finish executing.
         * 
         * @param pool The pool being waited on.
         */
        void wait(JobPool pool);
    };
}
