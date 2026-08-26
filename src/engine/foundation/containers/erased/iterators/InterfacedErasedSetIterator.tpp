/*
    ErasedSetIterator.tpp

    Template implementation of an iterator for an erased set.
*/


namespace toxico {
    template<bool Const, typename Interface>
    InterfacedErasedSetIterator_<Const, Interface>::InterfacedErasedSetIterator_(StorageIter iterator) noexcept
        : iterator_(iterator)
    {}

    template<bool Const, typename Interface>
    bool InterfacedErasedSetIterator_<Const, Interface>::operator==(const InterfacedErasedSetIterator_& other) const noexcept {
        return iterator_ == other.iterator_;
    }

    template<bool Const, typename Interface>
    InterfacedErasedSetIterator_<Const, Interface>& InterfacedErasedSetIterator_<Const, Interface>::operator++() noexcept {
        ++iterator_;
        return *this;
    }

    template<bool Const, typename Interface>
    InterfacedErasedSetIterator_<Const, Interface>::Reference InterfacedErasedSetIterator_<Const, Interface>::operator*() {
        return *iterator_->second.get();
    }

    template<bool Const, typename Interface>
    InterfacedErasedSetIterator_<Const, Interface>::Pointer InterfacedErasedSetIterator_<Const, Interface>::operator->() {
        return iterator_->second.get();
    }
}
