/*
    InterfacedErasedSetIterator.tpp

    Template implementation of an iterator for an interfaced erased set.
*/

namespace toxico {
    template<typename Interface>
    InterfacedErasedSetIterator<Interface>::InterfacedErasedSetIterator(Iterator iterator) noexcept
        : iterator_(iterator) {}

    template<typename Interface>
    bool InterfacedErasedSetIterator<Interface>::operator==(const InterfacedErasedSetIterator& other) const noexcept {
        return iterator_ == other.iterator_ && bucket_index_ == other.bucket_index_;
    }

    template<typename Interface>
    InterfacedErasedSetIterator<Interface>& InterfacedErasedSetIterator<Interface>::operator++() {
        ++iterator_;
        return *this;
    }

    template<typename Interface>
    const Interface& InterfacedErasedSetIterator<Interface>::operator*() {
        return iterator_->second->at(bucket_index_);
    }

    template<typename Interface>
    const Interface* InterfacedErasedSetIterator<Interface>::operator->() {
        return &iterator_->second->at(bucket_index_);
    }
}
