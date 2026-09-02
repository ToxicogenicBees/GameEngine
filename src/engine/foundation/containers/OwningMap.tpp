/*
    OwningMap.tpp

    Template implementation of a map holding polymorphic objects.
*/

namespace toxico {
    template<typename Key, typename Base>
    template<std::derived_from<Base> T>
    std::pair<typename OwningMap<Key, Base>::iterator, bool> OwningMap<Key, Base>::insert(std::pair<Key, T> item) {
        return data_.insert({
            item.first, std::make_unique<T>(item.second)
        });
    }

    template<typename Key, typename Base>
    template<std::derived_from<Base> T>
    std::pair<typename OwningMap<Key, Base>::iterator, bool> OwningMap<Key, Base>::insert(std::pair<Key, std::unique_ptr<T>> item) {
        return data_.insert({
            item.first, std::move(item.second)
        });
    }

    template<typename Key, typename Base>
    template<std::derived_from<Base> T, typename... Args>
    std::pair<typename OwningMap<Key, Base>::iterator, bool> OwningMap<Key, Base>::emplace(const Key& key, Args&& ...args) {
        return data_.emplace(
            key, std::make_unique<T>(std::forward<Args>(args)...)
        );
    }

    template<typename Key, typename Base>
    template<std::derived_from<Base> T, typename... Args>
    std::pair<typename OwningMap<Key, Base>::iterator, bool> OwningMap<Key, Base>::try_emplace(const Key& key, Args&& ...args) {
        return data_.try_emplace(
            key, std::make_unique<T>(std::forward<Args>(args)...)
        );
    }

    template<typename Key, typename Base>
    std::size_t OwningMap<Key, Base>::erase(const Key& key) noexcept {
        return data_.erase(key);
    }

    template<typename Key, typename Base>
    template<std::derived_from<Base> T>
    const T& OwningMap<Key, Base>::getAs(const Key& key) const {
        return static_cast<const T&>(get(key));
    }

    template<typename Key, typename Base>
    template<std::derived_from<Base> T>
    T& OwningMap<Key, Base>::getAs(const Key& key) {
        return static_cast<T&>(get(key));
    }

    template<typename Key, typename Base>
    const Base& OwningMap<Key, Base>::at(const Key& key) const {
        return *data_.at(key).get();
    }

    template<typename Key, typename Base>
    Base& OwningMap<Key, Base>::at(const Key& key) {
        return *data_.at(key).get();
    }

    template<typename Key, typename Base>
    bool OwningMap<Key, Base>::contains(const Key& key) const noexcept {
        return data_.contains(key);
    }

    template<typename Key, typename Base>
    bool OwningMap<Key, Base>::empty() const noexcept {
        return data_.empty();
    }

    template<typename Key, typename Base>
    std::size_t OwningMap<Key, Base>::size() const noexcept {
        return data_.size();
    }

    template<typename Key, typename Base>
    void OwningMap<Key, Base>::clear() {
        data_.clear();
    }

    template<typename Key, typename Base>
    OwningMap<Key, Base>::const_iterator OwningMap<Key, Base>::cbegin() const noexcept {
        return data_.cbegin();
    }

    template<typename Key, typename Base>
    OwningMap<Key, Base>::const_iterator OwningMap<Key, Base>::begin() const noexcept {
        return data_.begin();
    }

    template<typename Key, typename Base>
    OwningMap<Key, Base>::iterator OwningMap<Key, Base>::begin() noexcept {
        return data_.begin();
    }

    template<typename Key, typename Base>
    OwningMap<Key, Base>::const_iterator OwningMap<Key, Base>::cend() const noexcept {
        return data_.cend();
    }

    template<typename Key, typename Base>
    OwningMap<Key, Base>::const_iterator OwningMap<Key, Base>::end() const noexcept {
        return data_.end();
    }

    template<typename Key, typename Base>
    OwningMap<Key, Base>::iterator OwningMap<Key, Base>::end() noexcept {
        return data_.end();
    }
}
