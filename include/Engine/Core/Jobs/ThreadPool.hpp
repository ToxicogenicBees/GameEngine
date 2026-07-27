/*
    ThreadPool.hpp

    Declaration of a thread pool object.
*/

#pragma once

#include "Core/Jobs/WorkerThread.hpp"
#include "Core/Jobs/JobQueue.hpp"
#include "Core/Jobs/JobHandle.hpp"
#include "Foundation/Threading/Fence.hpp"

namespace toxico {
    class ThreadPool {
    private:
        const std::size_t THREADS_;

        JobQueue queue_;
        std::vector<WorkerThread> threads_;

        Fence pending_jobs_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param threads The number of threads in the pool.
         */
        ThreadPool(std::size_t threads);

        /**
         * @brief Submit a job to the pool.
         * 
         * @param task The task being submitted.
         * @return A handle for the submitted job.
         */
        JobHandle submit(std::function<void()> task);

        /**
         * @brief Gets the number of threads in the pool.
         * 
         * @return The number of threads in the pool.
         */
        std::size_t threads() const;

        /**
         * @brief Gets the number of currently pending jobs.
         * 
         * @return The number of currently pending jobs
         */
        std::size_t pending() const;

        /**
         * @brief Waits for all jobs in the queue to finish executing.
         */
        void wait() const;
    };
}
