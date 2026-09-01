/*
    ConditionalIterationRange.tpp

    Template implementation of a conditional iteration range.
*/

namespace toxico {
    template<typename Iterator, typename Condition>
    ConditionalIterationRange<Iterator, Condition>::ConditionalIterationRange(Iterator current, Iterator end, Condition condition)
        : begin_(ConditionalIterator<Iterator, Condition>(current, end, condition)),
          end_(ConditionalIterator<Iterator, Condition>(end, end, condition))
    {}

    template<typename Iterator, typename Condition>
    ConditionalIterator<Iterator, Condition> ConditionalIterationRange<Iterator, Condition>::begin() noexcept {
        return begin_;
    }

    template<typename Iterator, typename Condition>
    ConditionalIterator<Iterator, Condition> ConditionalIterationRange<Iterator, Condition>::end() noexcept {
        return end_;
    }
}
