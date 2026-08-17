/*
    ThreadPool.cpp

    Implementation of a thread pool object.
*/

#include "Core/Jobs/Threading/ThreadPool.hpp"

namespace toxico {
    ThreadPool::ThreadPool(size_t threads)
        : THREAD_COUNT_(threads),
          threads_(THREAD_COUNT_)
    {
        for (size_t i = 0; i < THREAD_COUNT_; ++i)
            threads_[i] = std::make_unique<WorkerThread>(queue_);
    }

    JobHandle ThreadPool::submit(std::function<void()> task) {
        return queue_.push([this, task = std::move(task)] {
            try {
                task();
            }
            catch (std::exception& e) {
                // @TODO: Handle error
            }
        });
    }

    size_t ThreadPool::threads() const {
        return THREAD_COUNT_;
    }
}
