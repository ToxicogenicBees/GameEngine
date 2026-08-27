/*
    ErasedSetIterator.tpp

    Template implementation of an iterator for an erased set.
*/

namespace toxico {
    template<bool Const>
    ErasedSetIterator_<Const>::ErasedSetIterator_(StorageIter iterator) noexcept
        : iterator_(iterator)
    {}

    template<bool Const>
    bool ErasedSetIterator_<Const>::operator==(const ErasedSetIterator_& other) const noexcept {
        return iterator_ == other.iterator_;
    }

    template<bool Const>
    ErasedSetIterator_<Const>& ErasedSetIterator_<Const>::operator++() noexcept {
        ++iterator_;
        return *this;
    }

    template<bool Const>
    ErasedSetIterator_<Const>::Reference ErasedSetIterator_<Const>::operator*() {
        return iterator_->second;
    }

    template<bool Const>
    ErasedSetIterator_<Const>::Pointer ErasedSetIterator_<Const>::operator->() {
        return &iterator_->second;
    }
}
