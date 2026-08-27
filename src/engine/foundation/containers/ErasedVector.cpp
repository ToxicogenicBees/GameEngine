/*
    ErasedVector.hpp

    Declaration of a type-erased collection of arbitrary data, stored in {numerical index, value} pairs.
*/

#include "foundation/containers/ErasedVector.hpp"

namespace toxico {
    ErasedVector::data_iterator ErasedVector::erase(data_const_iterator pos) {
        return data_.erase(pos);
    }

    ErasedVector::data_iterator ErasedVector::erase(data_const_iterator first, data_const_iterator last) {
        return data_.erase(first, last);
    }

    void ErasedVector::pop_back() noexcept {
        data_.pop_back();
    }

    void ErasedVector::resize(std::size_t size) {
        data_.resize(size);
    }

    void ErasedVector::reserve(std::size_t size) {
        data_.reserve(size);
    }

    bool ErasedVector::empty() const noexcept {
        return data_.empty();
    }

    std::size_t ErasedVector::capacity() const noexcept {
        return data_.capacity();
    }

    std::size_t ErasedVector::size() const noexcept {
        return data_.size();
    }

    void ErasedVector::clear() {
        data_.clear();
    }
}
