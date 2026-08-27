/*
    ErasedSet.tpp

    Template implementation of a type-erased collection of arbitrary data, stored in {type index, value} pairs.
*/

#include <stdexcept>
#include <utility>

namespace toxico {
    template<typename T>
    bool ErasedSet::insert(const T& value) {
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

    template<typename T, typename... Args>
    bool ErasedSet::emplace(Args&& ...args) {
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

    template<typename T>
    std::size_t ErasedSet::erase_type() noexcept {
        if (!contains_type<T>())
            return 0;

        // Remove subset
        auto& subset = get<T>();
        const auto removed_count = subset.size();
        data_.erase(typeid(T));

        return removed_count;
    }

    template<typename T>
    std::size_t ErasedSet::erase(const T& value) noexcept {
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

    template<typename T>
    const std::unordered_set<T>& ErasedSet::get() const {
        if (!contains_type<T>())
            throw std::invalid_argument("Erased set cannot fetch subset of non-stored type");

        // Fetch subset
        const auto& erased_bucket = *data_.at(typeid(T)).get();
        const auto& bucket = static_cast<const Bucket<T>&>(erased_bucket);
        return bucket.data;
    }

    template<typename T>
    std::unordered_set<T>& ErasedSet::get() {
        if (!contains_type<T>())
            throw std::invalid_argument("Erased set cannot fetch subset of non-stored type");

        // Fetch subset
        auto& erased_bucket = *data_.at(typeid(T)).get();
        auto& bucket = static_cast<Bucket<T>&>(erased_bucket);
        return bucket.data;
    }

    template<typename T>
    bool ErasedSet::contains_type() const noexcept {
        return data_.contains(typeid(T));
    }

    template<typename T>
    bool ErasedSet::contains(const T& value) const noexcept {
        if (!contains_type<T>())
            return false;

        const auto& subset = get<T>();
        return subset.contains(value);
    }
}
