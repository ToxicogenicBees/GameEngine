/*
    AsyncProcessQueue.cpp

    Implementation of a thread-safe queue for asynchronous processing of tasks across multiple cores.
*/

#include "Containers/AsyncProcessQueue.hpp"

AsyncProcessQueue::AsyncProcessQueue(size_t thread_count) 
    : threads_(thread_count == 0 ? std::thread::hardware_concurrency() : thread_count)
{
    auto run_tasks = [this]() {
        while (true) {
            std::function<void()> task;
            {
                std::lock_guard<std::mutex> lock(mutex_);
                if (queue_.empty()) {
                    break;
                }
                task = queue_.front();
                queue_.pop();
            }
            task();
        }
    };

    // Create threads
    for (size_t i = 0; i < threads_.size(); ++i)
        threads_.emplace_back(std::thread(run_tasks));

    // Detach threads
    for (auto& thread : threads_)
        thread.detach();
}

void AsyncProcessQueue::push(const std::function<void()>& task) {
    std::lock_guard<std::mutex> lock(mutex_);
    queue_.push(task);
}

bool AsyncProcessQueue::empty() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return queue_.empty();
}

size_t AsyncProcessQueue::size() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return queue_.size();
}

void AsyncProcessQueue::clear() {
    std::lock_guard<std::mutex> lock(mutex_);
    while (!queue_.empty())
        queue_.pop();
}
