/*
    IterationRange.tpp

    Template implementation of an iteration range.
*/

namespace toxico {
    template<typename Iterator>
    IterationRange<Iterator>::IterationRange(Iterator begin, Iterator end)
        : begin_(begin),
          end_(end)
    {}

    template<typename Iterator>
    Iterator IterationRange<Iterator>::begin() noexcept {
        return begin_;
    }

    template<typename Iterator>
    Iterator IterationRange<Iterator>::end() noexcept {
        return end_;
    }
}
