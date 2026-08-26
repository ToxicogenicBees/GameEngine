/*
    InterfacedErasedVector.tpp

    Template implementation of a type-erased collection of interfaced data, stored in {numerical index, value} pairs.
*/

#include <utility>

namespace toxico {
    template<typename Interface>
    template<std::derived_from<Interface> T>
    void InterfacedErasedVector<Interface>::push_back(const T& value) {
        data_.insert(
            std::make_unique<T>(value)
        );
    }

    template<typename Interface>
    template<std::derived_from<Interface> T, typename... Args>
    T& InterfacedErasedVector<Interface>::emplace_back(Args&& ...args) {
        data_.emplace_back(
            std::make_unique<T>(std::forward<Args>(args)...)
        );

        return back<T>();
    }

    template<typename Interface>
    InterfacedErasedVector<Interface>::iterator InterfacedErasedVector<Interface>::erase(const_iterator pos) {
        return data_.erase(pos);
    }

    template<typename Interface>
    InterfacedErasedVector<Interface>::iterator InterfacedErasedVector<Interface>::erase(const_iterator first, const_iterator last) {
        return data_.erase(first, last);
    }

    template<typename Interface>
    void InterfacedErasedVector<Interface>::pop_back() noexcept {
        data_.pop_back();
    }

    template<typename Interface>
    template<std::derived_from<Interface> T>
    const T& InterfacedErasedVector<Interface>::at(std::size_t index) const {
        return static_cast<const T&>(*data_.at(index));
    }

    template<typename Interface>
    template<std::derived_from<Interface> T>
    T& InterfacedErasedVector<Interface>::at(std::size_t index) {
        return static_cast<T&>(*data_.at(index));
    }

    template<typename Interface>
    const Interface& InterfacedErasedVector<Interface>::at(std::size_t index) const {
        return *data_.at(index);
    }

    template<typename Interface>
    Interface& InterfacedErasedVector<Interface>::at(std::size_t index) {
        return *data_.at(index);
    }

    template<typename Interface>
    template<std::derived_from<Interface> T>
    const T& InterfacedErasedVector<Interface>::front() const {
        return static_cast<const T&>(*data_.front());
    }

    template<typename Interface>
    template<std::derived_from<Interface> T>
    T& InterfacedErasedVector<Interface>::front() {
        return static_cast<T&>(*data_.front());
    }

    template<typename Interface>
    const Interface& InterfacedErasedVector<Interface>::front() const {
        return *data_.front();
    }

    template<typename Interface>
    Interface& InterfacedErasedVector<Interface>::front() {
        return *data_.front();
    }

    template<typename Interface>
    template<std::derived_from<Interface> T>
    const T& InterfacedErasedVector<Interface>::back() const {
        return static_cast<const T&>(*data_.back());
    }

    template<typename Interface>
    template<std::derived_from<Interface> T>
    T& InterfacedErasedVector<Interface>::back() {
        return static_cast<T&>(*data_.back());
    }

    template<typename Interface>
    const Interface& InterfacedErasedVector<Interface>::back() const {
        return *data_.back();
    }

    template<typename Interface>
    Interface& InterfacedErasedVector<Interface>::back() {
        return *data_.back();
    }

    template<typename Interface>
    void InterfacedErasedVector<Interface>::resize(std::size_t size) {
        return data_.resize(size);
    }

    template<typename Interface>
    void InterfacedErasedVector<Interface>::reserve(std::size_t size) {
        data_.reserve(size);
    }

    template<typename Interface>
    bool InterfacedErasedVector<Interface>::empty() const noexcept {
        return data_.empty();
    }

    template<typename Interface>
    std::size_t InterfacedErasedVector<Interface>::capacity() const noexcept {
        return data_.capacity();
    }

    template<typename Interface>
    std::size_t InterfacedErasedVector<Interface>::size() const noexcept {
        return data_.size();
    }

    template<typename Interface>
    void InterfacedErasedVector<Interface>::clear() {
        data_.clear();
    }
    
    template<typename Interface>
    InterfacedErasedVector<Interface>::const_iterator InterfacedErasedVector<Interface>::cbegin() const noexcept {
        return data_.cbegin();
    }

    template<typename Interface>
    InterfacedErasedVector<Interface>::const_iterator InterfacedErasedVector<Interface>::begin() const noexcept {
        return data_.begin();
    }

    template<typename Interface>
    InterfacedErasedVector<Interface>::iterator InterfacedErasedVector<Interface>::begin() noexcept {
        return data_.begin();
    }

    template<typename Interface>
    InterfacedErasedVector<Interface>::const_iterator InterfacedErasedVector<Interface>::cend() const noexcept {
        return data_.cend();
    }

    template<typename Interface>
    InterfacedErasedVector<Interface>::const_iterator InterfacedErasedVector<Interface>::end() const noexcept {
        return data_.end();
    }

    template<typename Interface>
    InterfacedErasedVector<Interface>::iterator InterfacedErasedVector<Interface>::end() noexcept {
        return data_.end();
    }
}
