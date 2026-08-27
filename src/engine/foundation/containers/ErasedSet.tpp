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
                std::make_any<std::unordered_set<T>>()
            );
        }
        auto& subset = std::any_cast<std::unordered_set<T>&>(data_.at(typeid(T)));;
            
        // Insert result
        auto result = subset.insert(value);
        if (result.second)
            ++size_;

        return result.second;
    }

    template<typename T, typename... Args>
    bool ErasedSet::emplace(Args&& ...args) {
        // Fetch subset
        if (!contains_type<T>()) {
            data_.emplace(
                std::type_index(typeid(T)),
                std::make_any<std::unordered_set<T>>()
            );
        }
        auto& subset = std::any_cast<std::unordered_set<T>&>(data_.at(typeid(T)));;
            
        // Emplace result
        auto result = subset.emplace(std::forward<Args>(args)...);
        if (result.second)
            ++size_;

        return result.second;
    }

    template<typename T>
    std::size_t ErasedSet::erase_type() noexcept {
        if (!contains_type<T>())
            return 0;

        // Remove subset
        auto& subset = get<T>();
        const auto removed_count = subset.size();
        size_ -= removed_count;
        data_.erase(typeid(T));

        return removed_count;
    }

    template<typename T>
    std::size_t ErasedSet::erase(const T& value) noexcept {
        if (!contains_type<T>())
            return 0;

        // Remove from subset
        auto& subset = get<T>();
        const auto removed_count = subset.erase(value);
        size_ -= removed_count;

        // Erase empty subsets
        if (subset.empty())
            data_.erase(typeid(T));

        return removed_count;
    }

    template<typename T>
    const std::unordered_set<T>& ErasedSet::get() const {
        if (!contains_type<T>())
            throw std::invalid_argument("Erased set cannot fetch subset of non-stored type");

        return std::any_cast<const std::unordered_set<T>&>(data_.at(typeid(T)));
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
