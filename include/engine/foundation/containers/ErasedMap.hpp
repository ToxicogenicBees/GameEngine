/*
    ErasedMap.hpp

    Declaration of a type-erased collection of arbitrary data, stored in {key, value} pairs.
*/

#pragma once

#include "foundation/containers/iterators/ErasedMapIterator.hpp"
#include "foundation/utility/IterationRange.hpp"
#include <unordered_map>
#include <typeindex>
#include <vector>
#include <any>

namespace toxico {
    template<typename Key>
    class ErasedMap {
    private:
        using Data = std::unordered_map<Key, std::any>;
        Data data_;

    public:
        template<typename T>
        using const_iterator = ErasedMapIterator<Key, T>;

        using data_iterator = Data::iterator;

        /**
         * @brief Inserts an item into the map.
         * 
         * @param value The item being inserted.
         * @return An iterator where the insertion took place, and a bool signaling if the insertion succeeded.
         */
        template<typename T>
        std::pair<data_iterator, bool> insert(std::pair<Key, T> pair);

        /**
         * @brief Emplaces an item into the map.
         * 
         * @param args The constructor arguments for the item.
         * @return An iterator where the insertion took place, and a bool signaling if the insertion succeeded.
         */
        template<typename T, typename... Args>
        std::pair<data_iterator, bool> emplace(const Key& key, Args&& ...args);

        /**
         * @brief Attempts to emplace an item into the map.
         * 
         * @param args The constructor arguments for the item.
         * @return An iterator where the insertion took place, and a bool signaling if the insertion succeeded.
         */
        template<typename T, typename... Args>
        std::pair<data_iterator, bool> try_emplace(const Key& key, Args&& ...args);

        /**
         * @brief Erases a type from the map.
         * 
         * @return The number of items erased.
         */
        template<typename T>
        std::size_t erase_type() noexcept;
        
        /**
         * @brief Erases an item from the map.
         * 
         * @param value The value being erased.
         * @return The number of items erased.
         */
        std::size_t erase(const Key& key) noexcept;

        /**
         * @brief Gets the item at the given key.
         * 
         * @param key The desired key.
         * @return The desired item.
         * 
         * Throws an error if no item with this key exists.
         * Throws an error if the cast is bad.
         */
        template<typename T>
        const T& at(const Key& key) const;
        template<typename T>
        T& at(const Key& key);

        /**
         * @brief Gets if the value at a key is of a specific type.
         * 
         * @return If the desired key has a value of the desired type.
         * 
         * Throws an error if no item with this key exists.
         */
        template<typename T>
        bool is_type(const Key& key) const noexcept;

        /**
         * @brief Gets if the map contains any items of a desired type.
         * 
         * @return If the map contains any items of a desired type.
         */
        template<typename T>
        bool contains_type() const noexcept;

        /**
         * @brief Gets if the map contains a specific item.
         * 
         * @param value The value being checked for.
         * @return If the map contains the specific item.
         */
        bool contains(const Key& key) const noexcept;

        /**
         * @brief Gets if the map is empty.
         * 
         * @return If the map is empty.
         */
        bool empty() const noexcept;

        /**
         * @brief Gets the number of types stored in the map.
         * 
         * @return The number of types stored in the map.
         */
        std::size_t type_count() const noexcept;

        /**
         * @brief Gets a list of types stored in the map.
         * 
         * @return A list of types stored in the map.
         */
        std::vector<std::type_index> types() const noexcept;

        /**
         * @brief Gets the size of the map.
         * 
         * @return The size of the map.
         */
        std::size_t size() const noexcept;

        /**
         * @brief Clears the map.
         */
        void clear();

        /**
         * @brief Gets an iteration range over all items of a specific type.
         * 
         * @return The desired iteration range.
         */
        template<typename T>
        IterationRange<const_iterator<T>> iterate() const noexcept;
    };
}

#include "foundation/containers/ErasedMap.tpp"
