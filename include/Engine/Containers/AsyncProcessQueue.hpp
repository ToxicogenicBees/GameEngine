/*
    AsyncProcessQueue.hpp

    Declaration of a thread-safe queue for asynchronous processing of tasks across multiple cores.
*/

#pragma once

#include <functional>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>

class AsyncProcessQueue {
private:
    std::queue<std::function<void()>> queue_;
    std::vector<std::thread> threads_;
    mutable std::mutex mutex_;

public:
    /**
     * @brief Constructor.
     * 
     * @param thread_count The number of threads to use for processing tasks.
     *                     If 0, uses the number of hardware threads.
     */
    AsyncProcessQueue(size_t thread_count = 0);

    /**
     * @brief Pushes a task into the queue.
     * 
     * @param task The task being pushed.
     */
    void push(const std::function<void()>& task);

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
};
