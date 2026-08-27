/*
    ErasedMap.tpp

    Template implementation of a type-erased collection of arbitrary data, stored in {key, value} pairs.
*/

#include <unordered_set>
#include <algorithm>
#include <utility>

namespace toxico {
    template<typename Key>
    template<typename T>
    std::pair<typename ErasedMap<Key>::iterator, bool> ErasedMap<Key>::insert(std::pair<Key, T> pair) {
        return data_.insert({
            pair.first,
            std::make_unique<T>(pair.second)
        });
    }

    template<typename Key>
    template<typename T, typename... Args>
    std::pair<typename ErasedMap<Key>::iterator, bool> ErasedMap<Key>::emplace(const Key& key, Args&& ...args) {
        return data_.emplace(
            key,
            std::make_any<T>(std::forward<Args>(args)...)
        );
    }

    template<typename Key>
    template<typename T, typename... Args>
    std::pair<typename ErasedMap<Key>::iterator, bool> ErasedMap<Key>::try_emplace(const Key& key, Args&& ...args) {
        return data_.try_emplace(
            key,
            std::make_any<T>(std::forward<Args>(args)...)
        );
    }

    template<typename Key>
    template<typename T>
    std::size_t ErasedMap<Key>::erase_type() noexcept {
        std::size_t result = 0;
        std::erase_if(data_, [this, &result](auto& item) {
            if (is_type<T>(item.first)) {
                ++result;
                return true;
            }
            return false;
        });

        return result;
    }
    
    template<typename Key>
    std::size_t ErasedMap<Key>::erase(const Key& key) noexcept {
        return data_.erase(key);
    }

    template<typename Key>
    template<typename T>
    const T& ErasedMap<Key>::at(const Key& key) const {
        return std::any_cast<const T&>(data_.at(key));
    }

    template<typename Key>
    template<typename T>
    T& ErasedMap<Key>::at(const Key& key) {
        return std::any_cast<T&>(data_.at(key));
    }

    template<typename Key>
    template<typename T>
    bool ErasedMap<Key>::is_type(const Key& key) const noexcept {
        return data_.at(key).type() == typeid(T);
    }

    template<typename Key>
    template<typename T>
    bool ErasedMap<Key>::contains_type() const noexcept {
        for (auto& [_, val] : data_) {
            if (val.second == typeid(T))
                return true;
        }

        return false;
    }

    template<typename Key>
    bool ErasedMap<Key>::contains(const Key& key) const noexcept {
        return data_.contains(key);
    }

    template<typename Key>
    bool ErasedMap<Key>::empty() const noexcept {
        return data_.empty();
    }

    template<typename Key>
    std::size_t ErasedMap<Key>::type_count() const noexcept {
        return types().size();
    }

    template<typename Key>
    std::vector<std::type_index> ErasedMap<Key>::types() const noexcept {
        std::unordered_set<std::type_index> result;

        for (auto& [_, val] : data_)
            result.insert(val.type());

        return {
            result.begin(),
            result.end()
        };
    }

    template<typename Key>
    std::size_t ErasedMap<Key>::size() const noexcept {
        return data_.size();
    }

    template<typename Key>
    void ErasedMap<Key>::clear() {
        return data_.clear();
    }
}
