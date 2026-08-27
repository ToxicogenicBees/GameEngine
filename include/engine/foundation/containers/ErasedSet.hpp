/*
    ErasedSet.hpp

    Declaration of a type-erased collection of arbitrary data, stored in {type index, value} pairs.
*/

#pragma once

#include <unordered_map>
#include <unordered_set>
#include <typeindex>
#include <vector>
#include <any>

namespace toxico {
    class ErasedSet {
    private:
        std::unordered_map<std::type_index, std::any> data_;
        std::size_t size_ = 0;

    public:
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
         * @brief Gets the collection of items in this set of the given type.
         * 
         * @return The item of that type.
         * 
         * Throws an error if no item of this type exists.
         * Throws an error if the cast is bad.
         */
        template<typename T>
        const std::unordered_set<T>& get() const;

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
    };
}

#include "foundation/containers/ErasedSet.tpp"
