/*
    IndexedList.tpp

    Template implementation of a bi-directional table for assigning indices to values.
*/

#include <algorithm>

namespace toxico {
    template<typename T, typename Index>
    std::pair<Index, bool>  IndexedList<T, Index>::insert(const T& value) noexcept {
        auto [iter, inserted] = lookup_.try_emplace(value, static_cast<Index>(values_.size()));
        if (inserted)
            values_.push_back(value);

        return {iter->second, inserted};
    }

    template<typename T, typename Index>
    Index IndexedList<T, Index>::index_of(const T& value) const noexcept {
        auto iter = lookup_.find(value);
        if (iter == lookup_.end())
            return this->invalid_index;

        return iter->second;
    }

    template<typename T, typename Index >
    const T& IndexedList<T, Index>::value_at(Index index) const {
        return values_.at(index);
    }

    template<typename T, typename Index >
    bool IndexedList<T, Index>::contains(const T& value) const noexcept {
        return lookup_.contains(value);
    }

    template<typename T, typename Index >
    IndexedList<T, Index>::size_type IndexedList<T, Index>::size() const noexcept {
        return values_.size();
    }

    template<typename T, typename Index >
    IndexedList<T, Index>::const_iterator IndexedList<T, Index>::cbegin() const noexcept {
        return values_.cbegin();
    }

    template<typename T, typename Index >
    IndexedList<T, Index>::const_iterator IndexedList<T, Index>::begin() const noexcept {
        return values_.begin();
    }

    template<typename T, typename Index >
    IndexedList<T, Index>::iterator IndexedList<T, Index>::begin() noexcept {
        return values_.begin();
    }

    template<typename T, typename Index >
    IndexedList<T, Index>::const_iterator IndexedList<T, Index>::cend() const noexcept {
        return values_.cend();
    }

    template<typename T, typename Index >
    IndexedList<T, Index>::const_iterator IndexedList<T, Index>::end() const noexcept {
        return values_.end();
    }

    template<typename T, typename Index >
    IndexedList<T, Index>::iterator IndexedList<T, Index>::end() noexcept {
        return values_.end();
    }
}
