/*
    IComponentPool.hpp

    An interface for a component pool.
*/

#pragma once

#include "foundation/containers/utility/DenseErasure.hpp"
#include <cstddef>

namespace toxico {
    class IComponentPool {
    public:
        /**
         * @brief Gets the size of the component pool.
         * 
         * @return The size of the component pool.
         */
        virtual std::size_t size() const noexcept = 0;

        /**
         * @brief Gets if this component pool is empty.
         * 
         * @return If the component pool is empty.
         */
        virtual bool empty() const noexcept = 0;

        /**
         * @brief Removes the last item from the component pool.
         */
        virtual void pop_back() noexcept = 0;

        /**
         * @brief Erases an item from the component pool.
         * 
         * @param index The index being erased.
         * @return If a swap occured or not.
         */
        virtual DenseErasure erase(std::size_t index) noexcept = 0;

        /**
         * @brief Inserts a defaulted item into the component pool.
         */
        virtual void push_back() = 0;

        /**
         * @brief Clears the data in this component pool.
         */
        virtual void clear() noexcept = 0;

        /**
         * @brief Copies an item from this pool to another.
         * 
         * @param source_index The source index of the item being copied.
         * @param destination The destination pool.
         * @param destination_index The destination index of the item being copied.
         */
        virtual void copyTo(std::size_t source_index, IComponentPool& destination, std::size_t destination_index) const = 0;
        
        /**
         * @brief Destructor.
         */
        virtual ~IComponentPool() = default;
    };
}
