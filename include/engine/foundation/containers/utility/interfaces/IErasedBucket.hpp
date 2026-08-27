/*
    IErasedBucket.hpp

    An interface for a bucket containing a set of arbitrary data.
*/

#pragma once

#include <cstddef>
#include <any>

namespace toxico {
    struct IErasedBucket {
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
        virtual ~IErasedBucket() = default;
    };
}
