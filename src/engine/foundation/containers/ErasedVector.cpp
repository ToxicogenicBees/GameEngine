/*
    ErasedVector.hpp

    Declaration of a type-erased collection of arbitrary data, stored in {numerical index, value} pairs.
*/

#include "foundation/containers/ErasedVector.hpp"

namespace toxico {
    ErasedVector::iterator ErasedVector::erase(const_iterator pos) {
        return data_.erase(pos);
    }

    ErasedVector::iterator ErasedVector::erase(const_iterator first, const_iterator last) {
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
    
    ErasedVector::const_iterator ErasedVector::cbegin() const noexcept {
        return data_.cbegin();
    }

    ErasedVector::const_iterator ErasedVector::begin() const noexcept {
        return data_.begin();
    }

    ErasedVector::iterator ErasedVector::begin() noexcept {
        return data_.begin();
    }

    ErasedVector::const_iterator ErasedVector::cend() const noexcept {
        return data_.cend();
    }

    ErasedVector::const_iterator ErasedVector::end() const noexcept {
        return data_.end();
    }

    ErasedVector::iterator ErasedVector::end() noexcept {
        return data_.end();
    }
}
