/*
    SmartHandle.tpp

    Template implementation of a smart handle class for caching run-time resources.
*/

#include "core/containers/SmartHandle.hpp"

namespace toxico {
    template<typename T>
    SmartHandle<T>::SmartHandle(SlotArray<T>& owner, uint32_t index, uint32_t generation) noexcept 
        : Handle<T>(generation, index),
        owner_(owner)
    {}

    template<typename T>
    SmartHandle<T>::SmartHandle(SlotArray<T>& owner, Handle<T> handle) noexcept 
        : Handle<T>(handle),
        owner_(owner)
    {}

    template<typename T>
    SmartHandle<T>::SmartHandle(SlotArray<T>& owner) noexcept
        : Handle<T>(),
        owner_(owner)
    {}

    template<typename T>
    bool SmartHandle<T>::has_value() const noexcept {
        return owner_.resolve(static_cast<Handle<T>>(*this)) != nullptr;
    }

    template<typename T>
    T& SmartHandle<T>::value() {
        return *owner_.resolve(static_cast<Handle<T>>(*this));
    }

    template<typename T>
    T SmartHandle<T>::value_or(T&& val) noexcept {
        if (has_value())
            return value();
        return val;
    }

    template<typename T>
    T& SmartHandle<T>::operator*() {
        return value();
    }

    template<typename T>
    SmartHandle<T>::operator bool() const noexcept {
        return has_value();
    }
}

namespace std {
    using toxico::SmartHandle;
    
    template<typename T>
    size_t hash<toxico::SmartHandle<T>>::operator()(const toxico::SmartHandle<T>& handle) const noexcept {
        uint64_t value = (static_cast<uint64_t>(handle.generation()) << 32) | handle.index();
        return std::hash<uint64_t>{}(value);
    }
}
