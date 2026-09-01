/*
    ConditionalIterator.tpp

    Template implementation of a conditional iterator, iterating over a region while
    skipping any item that doesn't meet the condition.
*/

namespace toxico {
    template<typename Iterator, typename Condition>
    ConditionalIterator<Iterator, Condition>::ConditionalIterator(Iterator current, Iterator end, Condition condition)
        : condition_(condition),
          current_(current),
          end_(end)
    {
        if (!condition_(*current_)) {
            while (current_ != end_ && !condition_(*current_))
                ++current_;
        }
    }

    template<typename Iterator, typename Condition>
    bool ConditionalIterator<Iterator, Condition>::operator==(const ConditionalIterator& other) const noexcept {
        return current_ == other.current_;
    }

    template<typename Iterator, typename Condition>
    ConditionalIterator<Iterator, Condition>& ConditionalIterator<Iterator, Condition>::operator++() {
        ++current_;
        while (current_ != end_ && !condition_(*current_))
            ++current_;

        return *this;
    }

    template<typename Iterator, typename Condition>
    decltype(auto) ConditionalIterator<Iterator, Condition>::operator*() {
        return *current_;
    }
}
