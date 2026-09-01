/*
    PolymorphicVector.tpp

    Template implementation of a vector holding polymorphic objects.
*/

#include <utility>

namespace toxico {
    template<typename Base>
    template<std::derived_from<Base> T>
    void PolymorphicVector<Base>::push_back(const T& item) {
        data_.push_back(std::make_unique<T>(item));
    }

    template<typename Base>
    template<std::derived_from<Base> T>
    void PolymorphicVector<Base>::push_back(std::unique_ptr<T> item) {
        data_.push_back(std::move(item));
    }

    template<typename Base>
    template<std::derived_from<Base> T, typename... Args>
    T& PolymorphicVector<Base>::emplace_back(Args&& ...args) {
        data_.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
    }

    template<typename Base>
    PolymorphicVector<Base>::iterator PolymorphicVector<Base>::erase(const_iterator pos) {
        return data_.erase(pos);
    }

    template<typename Base>
    PolymorphicVector<Base>::iterator PolymorphicVector<Base>::erase(const_iterator first, const_iterator last) {
        return data_.erase(first, last);
    }

    template<typename Base>
    void PolymorphicVector<Base>::pop_back() noexcept {
        data_.pop_back();
    }

    template<typename Base>
    template<std::derived_from<Base> T>
    const T& PolymorphicVector<Base>::at(std::size_t index) const {
        return static_cast<const T&>(at(index));
    }

    template<typename Base>
    template<std::derived_from<Base> T>
    T& PolymorphicVector<Base>::at(std::size_t index) {
        return static_cast<T&>(at(index));
    }

    template<typename Base>
    const Base& PolymorphicVector<Base>::at(std::size_t index) const {
        return *data_.at(index).get();
    }

    template<typename Base>
    Base& PolymorphicVector<Base>::at(std::size_t index) {
        return *data_.at(index).get();
    }

    template<typename Base>
    template<std::derived_from<Base> T>
    const T& PolymorphicVector<Base>::front() const {
        return static_cast<const T&>(front());
    }

    template<typename Base>
    template<std::derived_from<Base> T>
    T& PolymorphicVector<Base>::front() {
        return static_cast<T&>(front());
    }

    template<typename Base>
    const Base& PolymorphicVector<Base>::front() const {
        return *data_.front().get();
    }

    template<typename Base>
    Base& PolymorphicVector<Base>::front() {
        return *data_.front().get();
    }

    template<typename Base>
    template<std::derived_from<Base> T>
    const T& PolymorphicVector<Base>::back() const {
        return static_cast<const T&>(back());
    }
    
    template<typename Base>
    template<std::derived_from<Base> T>
    T& PolymorphicVector<Base>::back() {
        return static_cast<T&>(back());
    }
    
    template<typename Base>
    const Base& PolymorphicVector<Base>::back() const {
        return *data_.back().get();
    }
    
    template<typename Base>
    Base& PolymorphicVector<Base>::back() {
        return *data_.back().get();
    }
    
    template<typename Base>
    void PolymorphicVector<Base>::resize(std::size_t size) {
        data_.resize(size);
    }

    template<typename Base>
    void PolymorphicVector<Base>::reserve(std::size_t size) {
        data_.reserve(size);
    }

    template<typename Base>
    bool PolymorphicVector<Base>::empty() const noexcept {
        return data_.empty();
    }

    template<typename Base>
    std::size_t PolymorphicVector<Base>::capacity() const noexcept {
        return data_.capacity();
    }

    template<typename Base>
    std::size_t PolymorphicVector<Base>::size() const noexcept {
        return data_.size();
    }

    template<typename Base>
    void PolymorphicVector<Base>::clear() {
        data_.clear();
    }

    template<typename Base>
    PolymorphicVector<Base>::const_iterator PolymorphicVector<Base>::cbegin() const noexcept {
        return data_.cbegin();
    }

    template<typename Base>
    PolymorphicVector<Base>::const_iterator PolymorphicVector<Base>::begin() const noexcept {
        return data_.begin();
    }

    template<typename Base>
    PolymorphicVector<Base>::iterator PolymorphicVector<Base>::begin() noexcept {
        return data_.begin();
    }

    template<typename Base>
    PolymorphicVector<Base>::const_iterator PolymorphicVector<Base>::cend() const noexcept {
        return data_.cend();
    }

    template<typename Base>
    PolymorphicVector<Base>::const_iterator PolymorphicVector<Base>::end() const noexcept {
        return data_.end();
    }

    template<typename Base>
    PolymorphicVector<Base>::iterator PolymorphicVector<Base>::end() noexcept {
        return data_.end();
    }
}
