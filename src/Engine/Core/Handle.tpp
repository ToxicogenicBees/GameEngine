/*
    Handle.tpp

    Template implementation of a handle class for caching run-time resources.
*/

#pragma once

#include "Core/Handle.hpp"

template<typename T>
Handle<T>::Handle(uint32_t index, uint32_t generation)
    : GENERATION_(generation),
      index_(index)
{}

template<typename T>
uint32_t Handle<T>::index() const {
    return index_;
}

template<typename T>
uint32_t Handle<T>::generation() const {
    return GENERATION_;
}

template<typename T>
void Handle<T>::nullify() {
    index_ = invalid_index;
}

template<typename T>
bool Handle<T>::isNull() const {
    return index_ == invalid_index;
}

template<typename T>
Handle<T>::operator bool() const {
    return !isNull();
}

namespace std {
    template<typename T>
    size_t hash<Handle<T>>::operator()(const Handle<T>& handle) const noexcept {
        uint64_t value = (static_cast<uint64_t>(handle.generation()) << 32) | handle.index();
        return std::hash<uint64_t>{}(value);
    }
};
