/*
    InterfacedErasedSet.tpp

    Template implementation of a type-erased collection of interfaced data, stored in {type index, value} pairs.
*/

#include <utility>

namespace toxico {
    template<typename Interface>
    template<std::derived_from<Interface> T>
    bool InterfacedErasedSet<Interface>::insert(const T& value) {
        // Fetch subset
        if (!contains_type<T>()) {
            data_.emplace(
                std::type_index(typeid(T)),
                std::make_unique<Bucket<T>>()
            );
        }
        auto& erased_bucket = *data_.at(typeid(T)).get();
        auto& bucket = static_cast<Bucket<T>&>(erased_bucket);
            
        // Insert the value
        auto result = bucket.data.insert(value);
        return result.second;
    }

    template<typename Interface>
    template<std::derived_from<Interface> T, typename... Args>
    bool InterfacedErasedSet<Interface>::emplace(Args&& ...args) {
        // Fetch subset
        if (!contains_type<T>()) {
            data_.emplace(
                std::type_index(typeid(T)),
                std::make_unique<Bucket<T>>()
            );
        }
        auto& erased_bucket = *data_.at(typeid(T)).get();
        auto& bucket = static_cast<Bucket<T>&>(erased_bucket);
            
        // Emplace the value
        auto result = bucket.data.emplace(std::forward<Args>(args)...);
        return result.second;
    }

    template<typename Interface>
    template<std::derived_from<Interface> T>
    std::size_t InterfacedErasedSet<Interface>::erase(const T& value) noexcept {
        if (!contains_type<T>())
            return 0;

        // Remove from subset
        auto& erased_bucket = *data_.at(typeid(T)).get();
        auto& bucket = static_cast<Bucket<T>&>(erased_bucket);
        auto removed_count = bucket.data.erase(value);

        // Erase empty subsets
        if (bucket.empty())
            data_.erase(typeid(T));

        return removed_count;
    }

    template<typename Interface>
    template<std::derived_from<Interface> T>
    const std::unordered_set<T>& InterfacedErasedSet<Interface>::get() const {
        if (!contains_type<T>())
            throw std::invalid_argument("Interfaced erased set cannot fetch subset of non-stored type");

        // Fetch subset
        const auto& erased_bucket = *data_.at(typeid(T)).get();
        const auto& bucket = static_cast<const Bucket<T>&>(erased_bucket);
        return bucket.data;
    }

    template<typename Interface>
    template<std::derived_from<Interface> T>
    std::unordered_set<T>& InterfacedErasedSet<Interface>::get() {
        if (!contains_type<T>())
            throw std::invalid_argument("Erased set cannot fetch subset of non-stored type");

        // Fetch subset
        auto& erased_bucket = *data_.at(typeid(T)).get();
        auto& bucket = static_cast<Bucket<T>&>(erased_bucket);
        return bucket.data;
    }

    template<typename Interface>
    template<std::derived_from<Interface> T>
    bool InterfacedErasedSet<Interface>::contains_type() const noexcept {
        return data_.contains(typeid(T));
    }

    template<typename Interface>
    template<std::derived_from<Interface> T>
    bool InterfacedErasedSet<Interface>::contains(const T& value) const noexcept {
        if (!contains_type<T>())
            return false;

        const auto& subset = get<T>();
        return subset.contains(value);
    }

    template<typename Interface>
    bool InterfacedErasedSet<Interface>::empty() const noexcept {
        return data_.empty();
    }

    template<typename Interface>
    std::size_t InterfacedErasedSet<Interface>::type_count() const noexcept {
        return data_.size();
    }

    template<typename Interface>
    std::vector<std::type_index> InterfacedErasedSet<Interface>::types() const noexcept {
        std::vector<std::type_index> result;
        for (auto& [type, _] : data_)
            result.push_back(type);
        return result;
    }

    template<typename Interface>
    std::size_t InterfacedErasedSet<Interface>::size() const noexcept {
        std::size_t result = 0;
        for (const auto& [_, bucket] : data_)
            result += bucket.size();
        return result;
    }

    template<typename Interface>
    void InterfacedErasedSet<Interface>::clear() {
        data_.clear();
    }

    template<typename Interface>
    InterfacedErasedSet<Interface>::const_iterator InterfacedErasedSet<Interface>::cbegin() const noexcept {
        return InterfacedErasedSetIterator<Interface>(data_.cbegin());
    }

    template<typename Interface>
    InterfacedErasedSet<Interface>::const_iterator InterfacedErasedSet<Interface>::begin() const noexcept {
        return InterfacedErasedSetIterator<Interface>(data_.begin());
    }

    template<typename Interface>
    InterfacedErasedSet<Interface>::const_iterator InterfacedErasedSet<Interface>::cend() const noexcept {
        return InterfacedErasedSetIterator<Interface>(data_.cend());
    }

    template<typename Interface>
    InterfacedErasedSet<Interface>::const_iterator InterfacedErasedSet<Interface>::end() const noexcept {
        return InterfacedErasedSetIterator<Interface>(data_.end());
    }
}
