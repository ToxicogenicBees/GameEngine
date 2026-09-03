/*
    ErasedSet.hpp

    Declaration of a type-erased collection of arbitrary data, stored in {type index, value} pairs.
*/

#pragma once

#include "foundation/containers/utility/interfaces/IErasedBucket.hpp"
#include "foundation/containers/utility/ErasedBucket.hpp"
#include "foundation/utility/IterationRange.hpp"
#include "foundation/containers/OwningMap.hpp"
#include <unordered_map>
#include <unordered_set>
#include <typeindex>
#include <vector>
#include <memory>

namespace toxico {
    class ErasedSet {
    private:
        using IBucket = IErasedBucket;
        template<typename T>
        using Bucket = ErasedBucket<T>;

        OwningMap<std::type_index, IBucket> data_;

    public:
        template<typename T>
        using const_iterator = std::unordered_set<T>::const_iterator;

        /**
         * @brief Inserts an item into the set.
         * 
         * @param value The item being inserted.
         * @return A bool signaling if the insertion succeeded.
         */
        template<typename T>
        bool insert(const T& value);

        /**
         * @brief Emplaces an item into the set.
         * 
         * @param args The constructor arguments for the item.
         * @return A bool signaling if the emplacement succeeded.
         */
        template<typename T, typename... Args>
        bool emplace(Args&& ...args);

        /**
         * @brief Erases a type from the set.
         * 
         * @return The number of items erased.
         */
        template<typename T>
        std::size_t erase_type() noexcept;
        
        /**
         * @brief Erases an item from the set.
         * 
         * @param value The value being erased.
         * @return The number of items erased.
         */
        template<typename T>
        std::size_t erase(const T& value) noexcept;

        /**
         * @brief Gets if the set contains any items of a desired type.
         * 
         * @return If the set contains any items of a desired type.
         */
        template<typename T>
        bool contains_type() const noexcept;

        /**
         * @brief Gets if the set contains a specific item.
         * 
         * @param value The value being checked for.
         * @return If the set contains the specific item.
         */
        template<typename T>
        bool contains(const T& value) const noexcept;

        /**
         * @brief Gets if the set is empty.
         * 
         * @return If the set is empty.
         */
        bool empty() const noexcept;

        /**
         * @brief Gets the number of types stored in the set.
         * 
         * @return The number of types stored in the set.
         */
        std::size_t type_count() const noexcept;

        /**
         * @brief Gets a list of types stored in the set.
         * 
         * @return A list of types stored in the set.
         */
        std::vector<std::type_index> types() const noexcept;

        /**
         * @brief Gets the size of the set.
         * 
         * @return The size of the set.
         */
        std::size_t size() const noexcept;

        /**
         * @brief Clears the set.
         */
        void clear();

        /**
         * @brief Gets an iteration range over all items of a specific type.
         * 
         * @return The desired iteration range.
         * 
         * Throws an exception if no items of the desired type isn't stored in this set.
         */
        template<typename T>
        IterationRange<const_iterator<T>> iterate() const;
    };
}

#include "foundation/containers/ErasedSet.tpp"
