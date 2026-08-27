/*
    ErasedSet.cpp

    Implementation of a type-erased collection of arbitrary data, stored in {type index, value} pairs.
*/

#include "foundation/containers/ErasedSet.hpp"

namespace toxico {
    bool ErasedSet::empty() const noexcept {
        return data_.empty();
    }

    std::size_t ErasedSet::type_count() const noexcept {
        return data_.size();
    }

    std::vector<std::type_index> ErasedSet::types() const noexcept {
        std::vector<std::type_index> result;
        for (auto& [type, _] : data_)
            result.push_back(type);
        return result;
    }

    std::size_t ErasedSet::size() const noexcept {
        std::size_t result = 0;
        for (auto& [_, bucket] : data_)
            result += bucket->size();
        return result;
    }

    void ErasedSet::clear() {
        data_.clear();
    }
}
