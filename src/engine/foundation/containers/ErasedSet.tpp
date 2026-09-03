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
            data_.insert(
                std::type_index(typeid(T)),
                std::make_unique<Bucket<T>>()
            );
        }
        auto& bucket = data_.getAs<Bucket<T>>(typeid(T));
            
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
        auto& bucket = data_.getAs<Bucket<T>>(typeid(T));
            
        // Emplace the value
        auto result = bucket.data.emplace(std::forward<Args>(args)...);
        return result.second;
    }

    template<typename T>
    std::size_t ErasedSet::erase_type() noexcept {
        if (!contains_type<T>())
            return 0;

        // Remove bucket
        auto& erased_bucket = data_.at(typeid(T));
        const auto removed_count = erased_bucket.size();
        data_.erase(typeid(T));

        return removed_count;
    }

    template<typename T>
    std::size_t ErasedSet::erase(const T& value) noexcept {
        if (!contains_type<T>())
            return 0;

        // Remove from subset
        auto& bucket = data_.getAs<Bucket<T>>(typeid(T));
        auto removed_count = bucket.data.erase(value);

        // Erase empty subsets
        if (bucket.empty())
            data_.erase(typeid(T));

        return removed_count;
    }

    template<typename T>
    bool ErasedSet::contains_type() const noexcept {
        return data_.contains(typeid(T));
    }

    template<typename T>
    bool ErasedSet::contains(const T& value) const noexcept {
        if (!contains_type<T>())
            return false;

        auto& bucket = data_.getAs<Bucket<T>>(typeid(T));
        return bucket.data.contains(value);
    }

    template<typename T>
    IterationRange<ErasedSet::const_iterator<T>> ErasedSet::iterate() const {
        auto& bucket = data_.getAs<Bucket<T>>(typeid(T));

        return {
            bucket.data.begin(),
            bucket.data.end()
        };
    }
}
