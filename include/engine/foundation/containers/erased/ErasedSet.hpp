/*
    ErasedSet.hpp

    Declaration of a type-erased collection of arbitrary data, stored in {type index, value} pairs.
*/

#pragma once

#include "foundation/containers/erased/iterators/ErasedSetIterator.hpp"
#include <unordered_map>
#include <typeindex>
#include <any>

namespace toxico {
    class ErasedSet {
    private:
        using Data = std::unordered_map<std::type_index, std::any>;
        Data data_;

    public:
        using const_iterator = ConstErasedSetIterator;
        using iterator = ErasedSetIterator;

        /**
         * @brief Inserts an item into the set.
         * 
         * @param value The item being inserted.
         * @return An iterator to the key the type maps to, and a bool signaling if the insertion succeeded.
         */
        template<typename T>
        auto insert(const T& value);

        /**
         * @brief Emplaces an item into the set.
         * 
         * @param args The constructor arguments for the item.
         * @return An iterator to the key the type maps to, and a bool signaling if the emplacement succeeded.
         */
        template<typename T, typename... Args>
        auto emplace(Args&& ...args);

        /**
         * @brief Emplaces an item into the set at a certain key.
         * 
         * @param args The constructor arguments for the item.
         * @return An iterator to the key the type maps to, and a bool signaling if the emplacement succeeded.
         */
        template<typename T, typename... Args>
        auto try_emplace(Args&& ...args);

        /**
         * @brief Erases an item of the given type.
         * 
         * @return The number of items erased.
         */
        template<typename T>
        std::size_t erase() noexcept;

        /**
         * @brief Gets the item of a specific type.
         * 
         * @return The item of that type.
         * 
         * Throws an error if no item of this type exists.
         * Throws an error if the cast is bad.
         */
        template<typename T>
        const T& at() const;
        template<typename T>
        T& at();

        /**
         * @brief Gets if the set contains an item of a certain type.
         * 
         * @return If the set contains an item of a certain type.
         */
        template<typename T>
        bool contains() const noexcept;

        /**
         * @brief Gets if the set is empty.
         * 
         * @return If the set is empty.
         */
        bool empty() const noexcept;

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
         * @brief Gets the desired iterator for this set's items.
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

#include "foundation/containers/erased/ErasedSet.tpp"
