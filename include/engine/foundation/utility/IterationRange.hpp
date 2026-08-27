/*
    IterationRange.hpp

    Declaration of an iteration range.
*/

#pragma once

namespace toxico {
    template<typename Iterator>
    class IterationRange {
    private:
        Iterator begin_;
        Iterator end_;

    public:
        using iterator_type = Iterator;
        
        /**
         * @brief Constructor.
         */
        IterationRange(Iterator begin, Iterator end);

        /**
         * @brief Gets the beginning of this iteration range.
         * 
         * @return The beginning of this iteration range.
         */
        Iterator begin() noexcept;

        /**
         * @brief Gets the beginning of this iteration range.
         * 
         * @return The beginning of this iteration range.
         */
        Iterator end() noexcept;
    };
}

#include "foundation/utility/IterationRange.tpp"
