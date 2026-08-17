/*
    SlotArray.hpp

    Declaration of a handle/slot buffer for run-time resource management.
*/

#pragma once

#include "core/containers/interfaces/IResolver.hpp"
#include "core/containers/Handle.hpp"
#include <cstdint>
#include <vector>
#include <memory>

namespace toxico {
    template<typename T>
    class SlotArray : IResolver<Handle<T>, T> {
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
        std::pair<Handle<T>, T*> create(Args&& ...args);

        /**
         * @brief Destroy a handle.
         * 
         * @param handle The handle being destroyed.
         */
        void destroy(Handle<T>& handle);

        /**
         * @brief Resolve a handle.
         * 
         * @param handle The handle being resolved.
         * @return The resolved pointer.
         */
        const T* resolve(Handle<T> handle) const;
        
        /**
         * @brief Resolve a handle.
         * 
         * @param handle The handle being resolved.
         * @return The resolved pointer.
         */
        T* resolve(Handle<T> handle) final;

        /**
         * @brief Gets if the provided handle is valid.
         * 
         * @return If the handle is valid.
         */
        bool isValid(Handle<T> handle) const;
    };
}

#include "core/containers/SlotArray.tpp"
