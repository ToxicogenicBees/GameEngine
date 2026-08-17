/*
    ThreadPool.hpp

    Declaration of a thread pool object.
*/

#pragma once

#include "Core/Jobs/Threading/WorkerThread.hpp"
#include "Core/Jobs/JobQueue.hpp"
#include "Core/Jobs/JobHandle.hpp"
#include "Foundation/Threading/Fence.hpp"
#include <memory>

namespace toxico {
    class ThreadPool {
    private:
        const size_t THREAD_COUNT_;

        JobQueue queue_;
        std::vector<std::unique_ptr<WorkerThread>> threads_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param threads The number of threads in the pool.
         */
        ThreadPool(size_t threads = 0);

        /**
         * @brief Copy operations (deleted).
         */
        ThreadPool(const ThreadPool&) = delete;
        ThreadPool& operator=(const ThreadPool&) = delete;

        /**
         * @brief Move operations (deleted).
         */
        ThreadPool(ThreadPool&&) noexcept = delete;
        ThreadPool& operator=(ThreadPool&&) noexcept = delete;

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
        size_t threads() const;
    };
}
