/*
    ErasedMapIterator.tpp

    Template implementation of an iterator for an erased map.
*/

namespace toxico {
    template<typename Key, typename T>
    ErasedMapIterator<Key, T>::ErasedMapIterator(Iterator current, Iterator end) noexcept
        : current_(current),
          end_(end)
    {
        // Skip items not of the desired type
        while (current_ != end_ && current_->second.type() != typeid(T))
            ++current_;
    }

    template<typename Key, typename T>
    bool ErasedMapIterator<Key, T>::operator==(const ErasedMapIterator& other) const noexcept {
        return current_ == other.current_;
    }

    template<typename Key, typename T>
    ErasedMapIterator<Key, T>& ErasedMapIterator<Key, T>::operator++() {
        // Skip items not of the desired type
        while (++current_ != end_ && current_->second.type() != typeid(T));

        return *this;
    }

    template<typename Key, typename T>
    std::pair<Key, const T&> ErasedMapIterator<Key, T>::operator*() {
        return {
            current_->first,
            std::any_cast<const T&>(current_->second)
        };
    }
}
