/*
    SlotArray.hpp

    Declaration of a handle/slot buffer for run-time resource management.
*/

#pragma once

#include "foundation/containers/concepts/Handle.hpp"
#include <cstdint>
#include <vector>
#include <memory>
#include <utility>

namespace toxico {
    template<typename T, Handle H>
    class SlotArray {
    private:
        struct Slot {
            std::unique_ptr<T> object = nullptr;
            uint32_t generation = 0;
        };

        std::vector<Slot> slots_;
        std::vector<uint32_t> free_list_;

    public:
        /**
         * @brief Constructor.
         */
        SlotArray() = default;

        /**
         * @brief Create a handle.
         */
        template<typename... Args>
        std::pair<H, T*> create(Args&& ...args);

        /**
         * @brief Destroy a handle.
         * 
         * @param handle The handle being destroyed.
         */
        void destroy(H handle);

        /**
         * @brief Resolve a handle.
         * 
         * @param handle The handle being resolved.
         * @return The resolved pointer.
         */
        const T* resolve(H handle) const;
        
        /**
         * @brief Resolve a handle.
         * 
         * @param handle The handle being resolved.
         * @return The resolved pointer.
         */
        T* resolve(H handle);

        /**
         * @brief Gets if the provided handle is valid.
         * 
         * @return If the handle is valid.
         */
        bool isValid(H handle) const;
    };
}

#include "foundation/containers/SlotArray.tpp"
