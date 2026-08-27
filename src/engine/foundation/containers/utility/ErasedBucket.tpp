/*
    ErasedBucket.tpp

    Template implementation for a bucket containing a set of arbitrary data.
*/

namespace toxico {
    template<typename T>
    std::size_t ErasedBucket<T>::size() const noexcept {
        return data.size();
    }

    template<typename T>
    bool ErasedBucket<T>::empty() const noexcept {
        return data.empty();
    }
}
