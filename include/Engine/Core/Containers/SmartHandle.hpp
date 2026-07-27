/*
    SmartHandle.hpp

    Declaration of a smart handle class for caching run-time resources.
*/

#pragma once

#include "Core/Containers/SlotArray.hpp"
#include "Core/Containers/Handle.hpp"

namespace toxico {
    template<typename T>
    class SmartHandle : public Handle<T> {
    private:
        SlotArray<T>& owner_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param owner The owner of this handle.
         * @param index The index of this handle.
         * @param generation The generation of this handle.
         */
        SmartHandle(SlotArray<T>& owner, uint32_t index, uint32_t generation) noexcept;

        /**
         * @brief Constructor.
         * 
         * @param owner The owner of this handle.
         * @param handle The handle becoming a smart handle.
         */
        SmartHandle(SlotArray<T>& owner, Handle<T> handle) noexcept;

        /**
         * @brief Constructor.
         */
        SmartHandle(SlotArray<T>& owner) noexcept;

        /**
         * @brief Gets if there is a value stored.
         * 
         * @return If there is a value stored
         */
        bool has_value() const noexcept;

        /**
         * @brief Gets the stored value.
         * 
         * @return A reference to the stored value.
         */
        T& value() final;

        /**
         * @brief Gets the stored value, or defaults to the specified parameter.
         * 
         * @param val The defaulting value.
         * @return The stored value, or the defaulting value
         */
        T value_or(T&& val) noexcept;

        /**
         * @brief Dereference operator.
         * 
         * @return The stored value.
         */
        T& operator*();

        /**
         * @brief Boolean cast operator
         * 
         * @return If there is a value stored
         */
        operator bool() const noexcept;
    };
}

namespace std {
    using toxico::SmartHandle;

    template<typename T>
    struct hash<SmartHandle<T>> {
        /**
         * @brief Calculate a hash for a handle object.
         * 
         * @param handle A handle object.
         * @return A deterministic hash for the handle object.
         */
        std::size_t operator()(const SmartHandle<T>& handle) const noexcept;
    };
}

#include "Core/Containers/SmartHandle.tpp"
