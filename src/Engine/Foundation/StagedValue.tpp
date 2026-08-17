/*
    StagedValue.tpp

    Template implementation of a value which can be staged to update at a later time.
*/

#pragma once

#include "Foundation/StagedValue.hpp"

namespace toxico {
    template<typename T>
    constexpr StagedValue<T>::StagedValue(const T& initial)
        : current_(initial) {}

    template<typename T>
    constexpr StagedValue<T>::StagedValue(T&& initial)
        : current_(std::move(initial)) {}

    template<typename T>
    constexpr bool StagedValue<T>::operator==(const StagedValue<T>& other) const noexcept {
        return current_ = other.current_;
    }

    template<typename T>
    constexpr StagedValue<T>& StagedValue<T>::operator=(const T& value) {
        stage(value);
        return *this;
    }

    template<typename T>
    constexpr const std::optional<T>& StagedValue<T>::staged_value() const noexcept {
        return staged_;
    }

    template<typename T>
    constexpr std::optional<T>& StagedValue<T>::staged_value() noexcept {
        return staged_;
    }

    template<typename T>
    constexpr const T& StagedValue<T>::value() const noexcept {
        return current_;
    }

    template<typename T>
    constexpr T& StagedValue<T>::value() noexcept {
        return current_;
    }

    template<typename T>
    constexpr void StagedValue<T>::stage(T value) {
        staged_ = value;
    }

    template<typename T>
    constexpr bool StagedValue<T>::has_staged() const {
        return staged_.has_value();
    }

    template<typename T>
    constexpr bool StagedValue<T>::commit() {
        if (!staged_)
            return false;

        current_ = std::move(*staged_);
        staged_.reset();

        return true;
    }

    template<typename T>
    constexpr const T& StagedValue<T>::operator*() const noexcept {
        return current_;
    }

    template<typename T>
    constexpr T& StagedValue<T>::operator*() noexcept {
        return current_;
    }

    template<typename T>
    constexpr const T* StagedValue<T>::operator->() const noexcept {
        return &current_;
    }

    template<typename T>
    constexpr T* StagedValue<T>::operator->() noexcept {
        return &current_;
    }
}
