/*
    TypeKey.cpp

    Implementation of a type key, where the order of the types matters.
*/

#include "foundation/utility/TypeKey.hpp"
#include <algorithm>
#include <stdexcept>

namespace toxico {
    bool TypeKey::operator==(const TypeKey& other) const {
        if (size() != other.size())
            return false;

        for (const auto& type : types_) {
            if (!other.contains(type))
                return false;
        }

        return true;
    }

    bool TypeKey::contains(const std::type_index& type) const noexcept {
        auto iter = std::lower_bound(types_.begin(), types_.end(), type);
        return iter != types_.end();
    }

    std::type_index TypeKey::operator[](std::size_t index) const {
        return types_[index];
    }

    std::type_index TypeKey::at(std::size_t index) const {
        if (size() >= index)
            throw std::out_of_range("TypeKey indexed out of bounds");
        return types_[index];
    }

    std::size_t TypeKey::size() const noexcept {
        return types_.size();
    }

    bool TypeKey::empty() const noexcept {
        return types_.empty();
    }

    TypeKey::const_iterator TypeKey::cbegin() const noexcept {
        return types_.cbegin();
    }

    TypeKey::const_iterator TypeKey::begin() const noexcept {
        return types_.begin();
    }

    TypeKey::iterator TypeKey::begin() noexcept {
        return types_.begin();
    }

    TypeKey::const_iterator TypeKey::cend() const noexcept {
        return types_.cend();
    }

    TypeKey::const_iterator TypeKey::end() const noexcept {
        return types_.end();
    }

    TypeKey::iterator TypeKey::end() noexcept {
        return types_.end();
    }
}
