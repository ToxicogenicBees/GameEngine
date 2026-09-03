/*
    OwningMap.hpp

    Declaration of a map holding polymorphic objects.
*/

#pragma once

#include <type_traits>
#include <utility>
#include <unordered_map>
#include <memory>

namespace toxico {
    template<typename Key, typename Base>
    class OwningMap {
    private:
        using Map = std::unordered_map<Key, std::unique_ptr<Base>>;
        Map data_;

    public:
        using const_iterator = Map::const_iterator;
        using iterator = Map::iterator;

        /**
         * @brief Inserts an item into the map.
         * 
         * @param key The key being inserted into.
         * @param value The value being inserted.
         * @return An iterator to the insertion position, and a flag telling if the insertion was successful.
         */
        template<std::derived_from<Base> T = Base>
        std::pair<iterator, bool> insert(const Key& key, const T& value);

        /**
         * @brief Inserts an item into the map.
         * 
         * @param key The key being inserted into.
         * @param value The value being inserted.
         * @return An iterator to the insertion position, and a flag telling if the insertion was successful.
         */
        template<std::derived_from<Base> T = Base>
        std::pair<iterator, bool> insert(const Key& key, std::unique_ptr<T> value);

        /**
         * @brief Emplaces an item into the map.
         * 
         * @param args The constructor arguments for the item being emplaced.
         * @return An iterator to the insertion position, and a flag telling if the insertion was successful.
         */
        template<std::derived_from<Base> T = Base, typename... Args>
        std::pair<iterator, bool> emplace(const Key& key, Args&& ...args);

        /**
         * @brief Emplaces an item into the map.
         * 
         * @param args The constructor arguments for the item being emplaced.
         * @return An iterator to the insertion position, and a flag telling if the insertion was successful.
         */
        template<std::derived_from<Base> T = Base, typename... Args>
        std::pair<iterator, bool> try_emplace(const Key& key, Args&& ...args);

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
         */
        template<std::derived_from<Base> T>
        const T& getAs(const Key& key) const;
        template<std::derived_from<Base> T>
        T& getAs(const Key& key);

        /**
         * @brief Gets the item at the given key.
         * 
         * @param key The desired key.
         * @return The desired item.
         * 
         * Throws an error if no item with this key exists.
         */
        const Base& at(const Key& key) const;
        Base& at(const Key& key);

        /**
         * @brief Gets the item at the given key.
         * 
         * @param key The desired key.
         * @return The desired item.
         */
        const Base& operator[](const Key& key) const;
        Base& operator[](const Key& key);

        /**
         * @brief Gets if the map contains a specific item.
         * 
         * @param value The value being checked for.
         * @return If the map contains the specific item.
         */
        bool contains(const Key& key) const noexcept;

        /**
         * @brief Attempts to find the value at a given key.
         * 
         * @param key The key being searched for.
         * @return An iterator containing either where the item was found or the
         *         end of the map.
         */
        const_iterator find(const Key& key) const;
        iterator find(const Key& key);

        /**
         * @brief Gets if the map is empty.
         * 
         * @return If the map is empty.
         */
        bool empty() const noexcept;

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
         * @brief Gets the desired iterator for this map's {key, unique_ptr} pairs
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

#include "foundation/containers/OwningMap.tpp"
