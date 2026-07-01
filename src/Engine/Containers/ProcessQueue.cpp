/*
    ProcessQueue.cpp

    Implementation of a thread-safe queue for synchronous processing of tasks across multiple cores.
*/


#include "Containers/ProcessQueue.hpp"
#include "Containers/HandleBuffer.hpp"

void ProcessQueue::push(const std::function<void()>& task) {
    std::lock_guard<std::mutex> lock(mutex_);
    queue_.push(task);
}

void ProcessQueue::pop() {
    std::function<void()> task;
    {
        std::lock_guard<std::mutex> lock(mutex_);

        if (!queue_.empty()) {
            task = queue_.front();
            queue_.pop();
        }
    }
    task();
}

bool ProcessQueue::empty() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return queue_.empty();
}

size_t ProcessQueue::size() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return queue_.size();
}

void ProcessQueue::clear() {
    std::lock_guard<std::mutex> lock(mutex_);
    while(!queue_.empty())
        queue_.pop();
}

void ProcessQueue::executeAll(size_t thread_count) {
    if (thread_count == 0)
        thread_count = std::thread::hardware_concurrency();
    
    auto run_task = [this]() {
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
    std::vector<std::thread> thread_pool;
    for (size_t i = 0; i < thread_count; ++i)
        thread_pool.emplace_back(std::thread(run_task));

    // Join threads
    for (auto& thread : thread_pool)
        if (thread.joinable())
            thread.join();
}
