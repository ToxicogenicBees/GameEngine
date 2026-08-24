/*
    ComponentPool.tpp

    Template implementation of a component pool
*/

namespace toxico {
    template<Component C>
    const C& ComponentPool<C>::operator[](size_t index) const {
        return components_[index];
    }

    template<Component C>
    C& ComponentPool<C>::operator[](size_t index) {
        return components_[index];
    }

    template<Component C>
    const C& ComponentPool<C>::at(size_t index) const {
        return components_.at(index);
    }

    template<Component C>
    C& ComponentPool<C>::at(size_t index) {
        return components_.at(index);
    }

    template<Component C>
    size_t ComponentPool<C>::size() const noexcept {
        return components_.size();
    }

    template<Component C>
    bool ComponentPool<C>::empty() const noexcept {
        return components_.empty();
    }
    
    template<Component C>
    template<typename... Args>
    C& ComponentPool<C>::emplace_back(Args&&... args) {
        return components_.emplace_back(std::forward<Args>(args)...);
    }

    template<Component C>
    void ComponentPool<C>::push_back(const C& value) {
        components_.push_back(value);
    }

    template<Component C>
    void ComponentPool<C>::push_back(C&& value) {
        components_.push_back(std::move(value));
    }

    template<Component C>
    void ComponentPool<C>::push_back() {
        components_.push_back(C{});
    }

    template<Component C>
    void ComponentPool<C>::pop_back() noexcept {
        return components_.pop_back();
    }

    template<Component C>
    DenseErasure ComponentPool<C>::erase(size_t index) noexcept {
        return components_.erase(index);
    }

    template<Component C>
    void ComponentPool<C>::clear() noexcept {
        components_.clear();
    }

    template<Component C>
    void ComponentPool<C>::copyTo(size_t source_index, IComponentPool& destination, size_t destination_index) const {
        auto& target = static_cast<ComponentPool<C>&>(destination);
        target[destination_index] = components_[source_index];
    }

    template<Component C>
    ComponentPool<C>::const_iterator ComponentPool<C>::cbegin() const noexcept {
        return components_.cbegin();
    }

    template<Component C>
    ComponentPool<C>::const_iterator ComponentPool<C>::begin() const noexcept {
        return components_.begin();
    }

    template<Component C>
    ComponentPool<C>::iterator ComponentPool<C>::begin() noexcept {
        return components_.begin();
    }

    template<Component C>
    ComponentPool<C>::const_iterator ComponentPool<C>::cend() const noexcept {
        return components_.cend();
    }

    template<Component C>
    ComponentPool<C>::const_iterator ComponentPool<C>::end() const noexcept {
        return components_.end();
    }

    template<Component C>
    ComponentPool<C>::iterator ComponentPool<C>::end() noexcept {
        return components_.end();
    }
}
