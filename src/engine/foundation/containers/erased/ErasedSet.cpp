/*
    ErasedSet.cpp

    Implementation of a type-erased collection of arbitrary data, stored in {type index, value} pairs.
*/

#include "foundation/containers/erased/ErasedSet.hpp"

namespace toxico {
    bool ErasedSet::empty() const noexcept {
        return data_.empty();
    }

    std::size_t ErasedSet::size() const noexcept {
        return data_.size();
    }

    void ErasedSet::clear() {
        data_.clear();
    }

    ErasedSet::const_iterator ErasedSet::cbegin() const noexcept {
        return ConstErasedSetIterator(data_.cbegin());
    }

    ErasedSet::const_iterator ErasedSet::begin() const noexcept {
        return ConstErasedSetIterator(data_.begin());
    }

    ErasedSet::iterator ErasedSet::begin() noexcept {
        return ErasedSetIterator(data_.begin());
    }

    ErasedSet::const_iterator ErasedSet::cend() const noexcept {
        return ConstErasedSetIterator(data_.cend());
    }

    ErasedSet::const_iterator ErasedSet::end() const noexcept {
        return ConstErasedSetIterator(data_.end());
    }

    ErasedSet::iterator ErasedSet::end() noexcept {
        return ErasedSetIterator(data_.end());
    }
}
