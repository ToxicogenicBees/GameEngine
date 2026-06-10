/*
    RingBuffer.tpp

    Template implementation of a ring buffer.
*/

#pragma once

#include "Containers/RingBuffer.hpp"
#include <stdexcept>

template<typename T, size_t Size>
T& RingBuffer<T, Size>::front() {
    std::lock_guard guard(mutex);
    
    if (empty())
        throw std::runtime_error("Cannot fetch front of empty buffer");
    return buffer_[head_];
}

template<typename T, size_t Size>
T& RingBuffer<T, Size>::back() {
    std::lock_guard guard(mutex);

    if (empty())
        throw std::runtime_error("Cannot fetch front of empty buffer");
    return buffer_[tail_];
}

template<typename T, size_t Size>
void RingBuffer<T, Size>::push(const T& item) {
    std::lock_guard guard(mutex);

    if ((tail_ + 1) % Size == head_)
        throw std::runtime_error("Cannot push to full buffer");
    buffer_[tail_++] = item;
    ++count_;
}

template<typename T, size_t Size>
void RingBuffer<T, Size>::pop() {
    std::lock_guard guard(mutex);

    if (!empty()) {
        head_ = (head_ + 1) % Size;
        --count_;
    }
}

template<typename T, size_t Size>
bool RingBuffer<T, Size>::empty() const {
    std::lock_guard guard(mutex);

    return head_ == tail_;
}

template<typename T, size_t Size>
size_t RingBuffer<T, Size>::size() const {
    std::lock_guard guard(mutex);

    return count_;
}

template<typename T, size_t Size>
size_t RingBuffer<T, Size>::capacity() const {
    std::lock_guard guard(mutex);

    return Size;
}
