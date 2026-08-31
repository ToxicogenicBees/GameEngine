/*
    ConditionalIterationRange.hpp

    Declaration of a conditional iteration range.
*/

#pragma once

#include "foundation/utility/ConditionalIterator.hpp"

namespace toxico {
    template<typename Iterator, typename Condition>
    class ConditionalIterationRange {
    private:
        ConditionalIterator<Iterator, Condition> begin_;
        ConditionalIterator<Iterator, Condition> end_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param current The current iterator for the desired a range.
         * @param end The end iterator over the desired range.
         * @param condition The desired condition any iterated item should pass.
         */
        ConditionalIterationRange(Iterator current, Iterator end, Condition condition);

        /**
         * @brief Gets the beginning of this iteration range.
         * 
         * @return The beginning of this iteration range.
         */
        ConditionalIterator<Iterator, Condition> begin() noexcept;

        /**
         * @brief Gets the beginning of this iteration range.
         * 
         * @return The beginning of this iteration range.
         */
        ConditionalIterator<Iterator, Condition> end() noexcept;
    };
}

#include "foundation/utility/ConditionalIterationRange.tpp"
