/*
    ProcessQueue.hpp

    Declaration of a thread-safe queue for synchronous processing of tasks across multiple cores.
*/

#pragma once

#include <functional>
#include <thread>
#include <queue>
#include <mutex>

class ProcessQueue {
private:
    std::queue<std::function<void()>> queue_;
    mutable std::mutex mutex_;

public:
    /**
     * @brief Pushes a task into the queue.
     * 
     * @param task The task being pushed.
     */
    void push(const std::function<void()>& task);

    /**
     * @brief Pops a task from the queue and executes it.
     */
    void pop();

    /**
     * @brief Gets if the queue is empty.
     * 
     * @return If the queue is empty.
     */
    bool empty() const;

    /**
     * @brief Gets the size of the queue.
     * 
     * @return The size of the queue.
     */
    size_t size() const;

    /**
     * @brief Clears the queue.
     */
    void clear();

    /**
     * @brief Executes all tasks in the queue.
     * 
     * @param thread_count The number of threads to use for processing tasks.
     *                     If 0, uses the number of hardware threads.
     */
    void executeAll(size_t thread_count = 0);
};
