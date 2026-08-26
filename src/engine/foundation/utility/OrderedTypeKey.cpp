/*
    OrderedTypeKey.cpp

    Implementation of a type key, where the order of the types matters.
*/

#include "foundation/utility/OrderedTypeKey.hpp"
#include <algorithm>
#include <stdexcept>

namespace toxico {
    bool OrderedTypeKey::operator==(const OrderedTypeKey& other) const {
        if (size() != other.size())
            return false;

        for (size_t i = 0; i < size(); ++i) {
            if ((*this)[i] != other[i])
                return false;
        }

        return true;
    }

    bool OrderedTypeKey::contains(const std::type_index& type) const noexcept {
        auto iter = std::find(types_.begin(), types_.end(), type);
        return iter != types_.end();
    }

    std::type_index OrderedTypeKey::operator[](std::size_t index) const {
        return types_[index];
    }

    std::type_index OrderedTypeKey::at(std::size_t index) const {
        if (size() >= index)
            throw std::out_of_range("OrderedTypeKey indexed out of bounds");
        return types_[index];
    }

    std::size_t OrderedTypeKey::size() const noexcept {
        return types_.size();
    }

    bool OrderedTypeKey::empty() const noexcept {
        return types_.empty();
    }

    OrderedTypeKey::const_iterator OrderedTypeKey::cbegin() const noexcept {
        return types_.cbegin();
    }

    OrderedTypeKey::const_iterator OrderedTypeKey::begin() const noexcept {
        return types_.begin();
    }

    OrderedTypeKey::iterator OrderedTypeKey::begin() noexcept {
        return types_.begin();
    }

    OrderedTypeKey::const_iterator OrderedTypeKey::cend() const noexcept {
        return types_.cend();
    }

    OrderedTypeKey::const_iterator OrderedTypeKey::end() const noexcept {
        return types_.end();
    }

    OrderedTypeKey::iterator OrderedTypeKey::end() noexcept {
        return types_.end();
    }
}
