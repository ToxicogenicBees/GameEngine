/*
    InterfacedErasedSet.hpp

    Declaration of a type-erased collection of interfaced data, stored in {type index, value} pairs.
*/

#pragma once

#include "foundation/containers/erased/iterators/InterfacedErasedSetIterator.hpp"
#include <unordered_map>
#include <typeindex>
#include <utility>
#include <memory>
#include <concepts>

namespace toxico {
    template<typename Interface>
    class InterfacedErasedSet {
    private:
        using Data = std::unordered_map<std::type_index, std::unique_ptr<Interface>>;
        Data data_;

    public:
        using const_iterator = ConstInterfacedErasedSetIterator<Interface>;
        using iterator = InterfacedErasedSetIterator<Interface>;

        /**
         * @brief Inserts an item into the set.
         * 
         * @param value The item being inserted.
         * @return An iterator to the key the type maps to, and a bool signaling if the insertion succeeded.
         */
        template<std::derived_from<Interface> T>
        auto insert(const T& value);

        /**
         * @brief Emplaces an item into the set.
         * 
         * @param args The constructor arguments for the item.
         * @return An iterator to the key the type maps to, and a bool signaling if the emplacement succeeded.
         */
        template<std::derived_from<Interface> T, typename... Args>
        auto emplace(Args&& ...args);

        /**
         * @brief Emplaces an item into the set at a certain key.
         * 
         * @param args The constructor arguments for the item.
         * @return An iterator to the key the type maps to, and a bool signaling if the emplacement succeeded.
         */
        template<std::derived_from<Interface> T, typename... Args>
        auto try_emplace(Args&& ...args);

        /**
         * @brief Erases an item of the given type.
         * 
         * @return The number of items erased.
         */
        template<std::derived_from<Interface> T>
        std::size_t erase() noexcept;

        /**
         * @brief Erases an item of the given type.
         * 
         * @param type The type index of the desired item.
         * @return The number of items erased.
         */
        std::size_t erase(std::type_index type) noexcept;

        /**
         * @brief Gets the item of a specific type.
         * 
         * @return The item of that type.
         * 
         * Throws an error if no item of this type exists.
         * Throws an error if the cast is bad.
         */
        template<std::derived_from<Interface> T>
        const T& at() const;
        template<std::derived_from<Interface> T>
        T& at();

        /**
         * @brief Gets the item of a specific type.
         * 
         * @param type The type index of the desired item.
         * @return The item as a reference to its interface.
         * 
         * Throws an error if no item of this type exists.
         * Throws an error if the cast is bad.
         */
        const Interface& at(const std::type_index& type) const;
        Interface& at(const std::type_index& type);

        /**
         * @brief Gets if the set contains an item of a certain type.
         * 
         * @return If the set contains an item of a certain type.
         */
        template<std::derived_from<Interface> T>
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

#include "foundation/containers/erased/InterfacedErasedSet.tpp"
