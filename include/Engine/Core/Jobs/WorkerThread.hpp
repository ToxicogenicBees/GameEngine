/*
    WorkerThread.hpp

    Declaration of a working thread object.
*/

#pragma once

#include "Core/Jobs/JobQueue.hpp"
#include <condition_variable>
#include <optional>
#include <thread>
#include <atomic>

namespace toxico {
    class WorkerThread {
    private:
        JobQueue& queue_;
        std::jthread thread_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param queue The job queue used by this worker.
         */
        explicit WorkerThread(JobQueue& queue);

        /**
         * @brief Copy constructor (deleted).
         */
        WorkerThread(const WorkerThread&) = delete;

        /**
         * @brief Copy assignment operator (deleted).
         */
        WorkerThread& operator=(const WorkerThread&) = delete;

        /**
         * @brief Move constructor.
         */
        WorkerThread(WorkerThread&&) noexcept = default;

        /**
         * @brief Move assignment operator.
         */
        WorkerThread& operator=(WorkerThread&&) noexcept = default;

        /**
         * @brief Requests for this worker to stop working.
         */
        void stop();

        /**
         * @brief Destructor.
         */
        ~WorkerThread();
    };
}
