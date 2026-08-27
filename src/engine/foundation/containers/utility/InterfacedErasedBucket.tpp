/*
    InterfacedErasedBucket.tpp

    Template implementation for a bucket containing a set of data inheriting a shared interface.
*/

namespace toxico {
    template<typename Interface, std::derived_from<Interface> T>
    const Interface& InterfacedErasedBucket<Interface, T>::at(std::size_t index) const {
        auto iter = data.begin();
        for (size_t i = 0; i < index; ++i)
            ++iter;
        return *iter;
    }

    template<typename Interface, std::derived_from<Interface> T>
    std::size_t InterfacedErasedBucket<Interface, T>::size() const noexcept {
        return data.size();
    }

    template<typename Interface, std::derived_from<Interface> T>
    bool InterfacedErasedBucket<Interface, T>::empty() const noexcept {
        return data.empty();
    }
}
