/*
    ConditionalIterator.hpp

    Declaration of a conditional iterator, iterating over a region while
    skipping any item that doesn't meet the condition.
*/

#pragma once

#include <iterator>

namespace toxico {
    template<typename Iterator, typename Condition>
    class ConditionalIterator {
    private:
        Condition condition_;
        Iterator current_;
        Iterator end_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param current The current iterator for the desired a range.
         * @param end The end iterator over the desired range.
         * @param condition The desired condition any iterated item should pass.
         */
        ConditionalIterator(Iterator current, Iterator end, Condition condition);

        /**
         * @brief Comparison operator.
         * 
         * @param other Another iterator.
         * @return If the two iterators are the same.
         */
        bool operator==(const ConditionalIterator& other) const noexcept;

        /**
         * @brief Pre-increment operator.
         * 
         * @return A reference to the modified iterator.
         */
        ConditionalIterator& operator++();

        /**
         * @brief Dereference operator.
         * 
         * @return A reference to the object at this iterator.
         */
        decltype(auto) operator*();
    };
}

#include "foundation/utility/ConditionalIterator.tpp"
