/*
    InterfacedErasedBucket.hpp

    Implementation for a bucket containing a set of data inheriting a shared interface.
*/

#pragma once

#include "foundation/containers/utility/interfaces/IInterfacedErasedBucket.hpp"
#include <unordered_set>
#include <concepts>
#include <cstddef>

namespace toxico {
    template<typename Interface, std::derived_from<Interface> T>
    struct InterfacedErasedBucket final : IInterfacedErasedBucket<Interface> {
        std::unordered_set<T> data;

        /**
         * @brief Gets an item in the bucket;
         * 
         * @param index The index of the item.
         * @return The desired item.
         */
        const Interface& at(std::size_t index) const final;

        /**
         * @brief Gets the size of the bucket.
         * 
         * @return The size of the bucket.
         */
        std::size_t size() const noexcept final;

        /**
         * @brief Gets if the bucket is empty.
         * 
         * @return If the bucket is empty.
         */
        bool empty() const noexcept final;
    };
}

#include "foundation/containers/utility/InterfacedErasedBucket.tpp"
