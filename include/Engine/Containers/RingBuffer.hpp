/*
    RingBuffer.hpp

    Declaration of a ring buffer.
*/

#pragma once

#include <cstdint>
#include <array>
#include <mutex>

template<typename T, size_t Size>
class RingBuffer {
private:
    std::array<T, Size> buffer_;
    std::mutex mutex_;
    size_t count_ = 0;
    size_t head_ = 0;
    size_t tail_ = 0;

public:
    /**
     * @brief Constructor.
     */
    RingBuffer() = default;

    /**
     * @brief Gets the first element in the buffer.
     * 
     * @return The first element in the buffer.
     */
    T& front();

     /**
     * @brief Gets the last element in the buffer.
     * 
     * @return The last element in the buffer.
     */
    T& back();

    /**
     * @brief Pushes an item into the buffer.
     * 
     * @param item The item being pushed.
     */
    void push(const T& item);

    /**
     * @brief Pops an item from the buffer.
     */
    void pop();

    /**
     * @brief Gets if the buffer is empty.
     * 
     * @return If the buffer is empty.
     */
    bool empty() const;

    /**
     * @brief Gets the number of elements in the buffer.
     * 
     * @return The number of elements in the buffer.
     */
    size_t size() const;

    /**
     * @brief Gets the capacity of the buffer.
     * 
     * @return The capacity of the buffer.
     */
    size_t capacity() const;
};

#include "Containers/RingBuffer.hpp"
