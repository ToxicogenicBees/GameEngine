/*
    ThreadPool.cpp

    Implementation of a thread pool object.
*/

#include "Core/Jobs/ThreadPool.hpp"
#include <iostream>

namespace toxico {
    ThreadPool::ThreadPool(std::size_t threads)
        : THREADS_(threads)
    {
        threads_.reserve(THREADS_);
        for (std::size_t i = 0; i < THREADS_; ++i)
            threads_.emplace_back(queue_);
    }

    JobHandle ThreadPool::submit(std::function<void()> task) {
        auto run_task = [this, task = std::move(task)] {
            try {
                task();
            }
            catch (std::exception& e) {
                // @TODO: Handle error
            }
        };

        auto on_complete = [this] {
            pending_jobs_.complete();
        };

        pending_jobs_.add();
        return queue_.push(run_task, on_complete);
    }

    std::size_t ThreadPool::threads() const {
        return THREADS_;
    }

    std::size_t ThreadPool::pending() const {
        return pending_jobs_.pending();
    }

    void ThreadPool::wait() const {
        pending_jobs_.wait();
    }
}
