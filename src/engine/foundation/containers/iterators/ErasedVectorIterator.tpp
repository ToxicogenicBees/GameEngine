/*
    ErasedVectorIterator.tpp

    Template implementation of an iterator for an erased vector.
*/

namespace toxico {
    template<bool Const, typename T>
    ErasedVectorIterator_<Const, T>::ErasedVectorIterator_(Iterator current, Iterator end) noexcept
        : current_(current),
          end_(end)
    {
        // Skip items not of the desired type
        while (current_ != end_ && current_->type() != typeid(T))
            ++current_;
    }

    template<bool Const, typename T>
    bool ErasedVectorIterator_<Const, T>::operator==(const ErasedVectorIterator_& other) const noexcept {
        return current_ == other.current_;
    }

    template<bool Const, typename T>
    ErasedVectorIterator_<Const, T>& ErasedVectorIterator_<Const, T>::operator++() {
        // Skip items not of the desired type
        while (++current_ != end_ && current_->type() != typeid(T));

        return *this;
    }

    template<bool Const, typename T>
    ErasedVectorIterator_<Const, T>::Reference ErasedVectorIterator_<Const, T>::operator*() {
        return std::any_cast<Reference>(*current_);
    }

    template<bool Const, typename T>
    ErasedVectorIterator_<Const, T>::Pointer ErasedVectorIterator_<Const, T>::operator->() {
        return &std::any_cast<Reference>(*current_);
    }
}
