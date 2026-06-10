/*
    Handle.hpp

    Declaration of a handle class for caching run-time resources.
*/

#pragma once

#include <functional>
#include <cstdint>
#include <limits>

template<typename T>
class Handle {
private:
    uint32_t GENERATION_ = 0;
    uint32_t index_ = invalid_index;

public:
    static constexpr uint32_t invalid_index = std::numeric_limits<uint32_t>::max();

    /**
     * @brief Constructor.
     * 
     * @param index The index of this handle.
     * @param generation The generation of this handle.
     */
    Handle(uint32_t index, uint32_t generation);

    /**
     * @brief Equality operator.
     * 
     * @param other Another handle object
     */
    bool operator==(const Handle<T>&) const = default;

    /**
     * @brief Constructor.
     */
    Handle() = default;

    /**
     * @brief Gets the index of this handle.
     * 
     * @return The index of this handle.
     */
    uint32_t index() const;

    /**
     * @brief Gets the generation of this handle.
     * 
     * @return The generation of this handle.
     */
    uint32_t generation() const;

    /**
     * @brief Nullifies the handle.
     */
    void nullify();

    /**
     * @brief Gets if the handle is nullified.
     * 
     * @return If the handle is nullified.
     */
    bool isNull() const;

    /**
     * @brief bool() override.
     * 
     * @return If the handle is valid.
     */
    operator bool() const;
};

namespace std {
    template<typename T>
    struct hash<Handle<T>> {
        /**
         * @brief Calculate a hash for a handle object.
         * 
         * @param handle A handle object.
         * @return A deterministic hash for the handle object.
         */
        size_t operator()(const Handle<T>& handle) const noexcept;
    };
}

#include "Core/Handle.tpp"
