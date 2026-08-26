/*
    ErasedSet.hpp

    Declaration of a type-erased collection of arbitrary data, stored in {type index, value} pairs.
*/

#pragma once

#include "foundation/containers/erased/ErasedSet.hpp"
#include <utility>

namespace toxico {
    template<typename T>
    auto ErasedSet::insert(const T& value) {
        return data_.insert({
            std::type_index(typeid(T)),
            std::make_any<T>(value)
        });
    }

    template<typename T, typename... Args>
    auto ErasedSet::emplace(Args&& ...args) {
        return data_.emplace(
            std::type_index(typeid(T)),
            std::make_any<T>(std::forward<Args>(args)...)
        );
    }

    template<typename T, typename... Args>
    auto ErasedSet::try_emplace(Args&& ...args) {
        return data_.try_emplace(
            std::type_index(typeid(T)),
            std::make_any<T>(std::forward<Args>(args)...)
        );
    }

    template<typename T>
    std::size_t ErasedSet::erase() noexcept {
        return data_.erase(typeid(T));
    }

    template<typename T>
    const T& ErasedSet::at() const {
        return std::any_cast<const T&>(data_.at(typeid(T)));
    }

    template<typename T>
    T& ErasedSet::at() {
        return std::any_cast<T&>(data_.at(typeid(T)));
    }

    template<typename T>
    bool ErasedSet::contains() const noexcept {
        return data_.contains(typeid(T));
    }
}
