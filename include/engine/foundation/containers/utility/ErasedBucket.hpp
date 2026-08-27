/*
    ErasedBucket.hpp

    Declaration for a bucket containing a set of arbitrary data.
*/

#pragma once

#include "foundation/containers/utility/interfaces/IErasedBucket.hpp"
#include <unordered_set>
#include <concepts>
#include <cstddef>
#include <any>

namespace toxico {
    template<typename T>
    struct ErasedBucket final : IErasedBucket {
        std::unordered_set<T> data;

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

#include "foundation/containers/utility/ErasedBucket.tpp"
