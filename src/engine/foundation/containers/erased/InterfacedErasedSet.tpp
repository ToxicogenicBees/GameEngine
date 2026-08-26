/*
    InterfacedErasedSet.tpp

    Template implementation of a type-erased collection of interfaced data, stored in {type index, value} pairs.
*/

#include <utility>

namespace toxico {
    template<typename Interface>
    template<std::derived_from<Interface> T>
    auto InterfacedErasedSet<Interface>::insert(const T& value) {
        return data_.insert(
            std::type_index(typeid(T)),
            std::make_unique<T>(value)
        );
    }

    template<typename Interface>
    template<std::derived_from<Interface> T, typename... Args>
    auto InterfacedErasedSet<Interface>::emplace(Args&& ...args) {
        return data_.emplace(
            std::type_index(typeid(T)),
            std::make_unique<T>(std::forward<Args>(args)...)
        );
    }

    template<typename Interface>
    template<std::derived_from<Interface> T, typename... Args>
    auto InterfacedErasedSet<Interface>::try_emplace(Args&& ...args) {
        return data_.try_emplace(
            std::type_index(typeid(T)),
            std::make_unique<T>(std::forward<Args>(args)...)
        );
    }

    template<typename Interface>
    template<std::derived_from<Interface> T>
    std::size_t InterfacedErasedSet<Interface>::erase() noexcept {
        return erase(typeid(T));
    }

    template<typename Interface>
    std::size_t InterfacedErasedSet<Interface>::erase(std::type_index type) noexcept {
        return data_.erase(type);
    }

    template<typename Interface>
    template<std::derived_from<Interface> T>
    const T& InterfacedErasedSet<Interface>::at() const {
        return static_cast<const T&>(at(typeid(T)));
    }

    template<typename Interface>
    template<std::derived_from<Interface> T>
    T& InterfacedErasedSet<Interface>::at() {
        return static_cast<T&>(at(typeid(T)));
    }

    template<typename Interface>
    const Interface& InterfacedErasedSet<Interface>::at(const std::type_index& type) const {
        return *data_.at(type).get();
    }

    template<typename Interface>
    Interface& InterfacedErasedSet<Interface>::at(const std::type_index& type) {
        return *data_.at(type).get();
    }

    template<typename Interface>
    template<std::derived_from<Interface> T>
    bool InterfacedErasedSet<Interface>::contains() const noexcept {
        return data_.contains(typeid(T));
    }

    template<typename Interface>
    bool InterfacedErasedSet<Interface>::empty() const noexcept {
        return data_.empty();
    }

    template<typename Interface>
    std::size_t InterfacedErasedSet<Interface>::size() const noexcept {
        return data_.size();
    }

    template<typename Interface>
    void InterfacedErasedSet<Interface>::clear() {
        data_.clear();
    }

    template<typename Interface>
    InterfacedErasedSet<Interface>::const_iterator InterfacedErasedSet<Interface>::cbegin() const noexcept {
        return ConstInterfacedErasedSetIterator<Interface>(data_.cbegin());
    }

    template<typename Interface>
    InterfacedErasedSet<Interface>::const_iterator InterfacedErasedSet<Interface>::begin() const noexcept {
        return ConstInterfacedErasedSetIterator<Interface>(data_.begin());
    }
    
    template<typename Interface>
    InterfacedErasedSet<Interface>::iterator InterfacedErasedSet<Interface>::begin() noexcept {
        return InterfacedErasedSetIterator<Interface>(data_.begin());
    }

    template<typename Interface>
    InterfacedErasedSet<Interface>::const_iterator InterfacedErasedSet<Interface>::cend() const noexcept {
        return ConstInterfacedSetErasedIterator<Interface>(data_.cend());
    }

    template<typename Interface>
    InterfacedErasedSet<Interface>::const_iterator InterfacedErasedSet<Interface>::end() const noexcept {
        return ConstInterfacedSetErasedIterator<Interface>(data_.end());
    }

    template<typename Interface>
    InterfacedErasedSet<Interface>::iterator InterfacedErasedSet<Interface>::end() noexcept {
        return InterfacedErasedSetIterator<Interface>(data_.end());
    }
}
