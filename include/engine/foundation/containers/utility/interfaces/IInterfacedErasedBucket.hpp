/*
    IInterfacedErasedBucket.hpp

    An interface for a bucket containing a set of data inheriting a shared interface.
*/

#pragma once

#include <cstddef>

namespace toxico {
    template<typename Interface>
    struct IInterfacedErasedBucket {
        /**
         * @brief Gets an item in the bucket;
         * 
         * @param index The index of the item.
         * @return The desired item.
         */
        virtual const Interface& at(std::size_t index) const = 0;

        /**
         * @brief Gets the size of the bucket.
         * 
         * @return The size of the bucket.
         */
        virtual std::size_t size() const noexcept = 0;

        /**
         * @brief Gets if the bucket is empty.
         * 
         * @return If the bucket is empty.
         */
        virtual bool empty() const noexcept = 0;

        /**
         * @brief Destructor.
         */
        virtual ~IInterfacedErasedBucket() = default;
    };
}
