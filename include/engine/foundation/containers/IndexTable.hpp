/*
    IndexTable.hpp

    Declaration of a bi-directional table for assigning indices to values.
*/

#pragma once

#include <unordered_map>
#include <vector>
#include <cstddef>
#include <limits>

namespace toxico {
    template<typename T, typename Index = size_t>
    class IndexTable {
    private:
        std::unordered_map<T, Index> lookup_;
        std::vector<T> values_;

    public:
        using value_type = T;
        using index_type = Index;
        using size_type = Index;
        using const_iterator = std::vector<value_type>::const_iterator;
        using iterator = std::vector<value_type>::iterator;
        
        static constexpr size_type invalid_index = std::numeric_limits<size_type>::max();

        /**
         * @brief Inserts a value into the table.
         * 
         * @return The index of the value in the table.
         */
        Index insert(const T& value) noexcept;

        /**
         * @brief Gets the index of a value in the table.
         * 
         * @return The index of the value in the table, or
         *         invalid_index if the item has no index.
         */
        Index index_of(const T& value) const noexcept;

        /**
         * @brief Gets the value at a given index.
         * 
         * @return The value at the index.
         * 
         * Throws an exception if the index if out of range.
         */
        const T& value_at(Index index) const;

        /**
         * @brief Gets if a value is indexed in the table.
         * 
         * @return If the value is indexed in the table.
         */
        bool contains(const T& value) const noexcept;

        /**
         * @brief Gets the number of values indexed in the table.
         * 
         * @return The number of values indexed in the table.
         */
        size_type size() const noexcept;

        /**
         * @brief Gets the desired iterator for this table's values, in index order.
         * 
         * @return The desired iterator.
         */
        const_iterator cbegin() const noexcept;
        const_iterator begin() const noexcept;
        iterator begin() noexcept;
        const_iterator cend() const noexcept;
        const_iterator end() const noexcept;
        iterator end() noexcept;
    };
}

#include "foundation/containers/IndexTable.tpp"