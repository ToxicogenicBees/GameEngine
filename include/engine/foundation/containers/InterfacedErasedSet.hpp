/*
    InterfacedErasedSet.hpp

    Declaration of a type-erased collection of interfaced data, stored in {type index, value} pairs.
*/

#pragma once

#include "foundation/containers/utility/interfaces/IInterfacedErasedBucket.hpp"
#include "foundation/containers/utility/InterfacedErasedBucket.hpp"
#include "foundation/containers/iterators/InterfacedErasedSetIterator.hpp"
#include <unordered_map>
#include <typeindex>
#include <concepts>
#include <vector>
#include <any>

namespace toxico {
    template<typename Interface>
    class InterfacedErasedSet {
    private:
        using IBucket = IInterfacedErasedBucket<Interface>;
        template<std::derived_from<Interface> T>
        using Bucket = InterfacedErasedBucket<Interface, T>;

        std::unordered_map<std::type_index, std::unique_ptr<IBucket>> data_;

    public:
        using const_iterator = InterfacedErasedSetIterator<Interface>;

        /**
         * @brief Inserts an item into the set.
         * 
         * @param value The item being inserted.
         * @return A bool signaling if the insertion succeeded.
         */
        template<std::derived_from<Interface> T>
        bool insert(const T& value);

        /**
         * @brief Emplaces an item into the set.
         * 
         * @param args The constructor arguments for the item.
         * @return A bool signaling if the emplacement succeeded.
         */
        template<std::derived_from<Interface> T, typename... Args>
        bool emplace(Args&& ...args);

        /**
         * @brief Erases a type from the set.
         * 
         * @return The number of items erased.
         */
        template<std::derived_from<Interface> T>
        std::size_t erase_type() noexcept;

        /**
         * @brief Erases a type from the set.
         * 
         * @return The number of items erased.
         */
        std::size_t erase_type(const std::type_index& type) noexcept;

        /**
         * @brief Erases an item from the set.
         * 
         * @param value The value being erased.
         * @return The number of items erased.
         */
        template<std::derived_from<Interface> T>
        std::size_t erase(const T& value) noexcept;

        /**
         * @brief Gets the collection of items in this set of the given type.
         * 
         * @return The item of that type.
         * 
         * Throws an error if no item of this type exists.
         * Throws an error if the cast is bad.
         */
        template<std::derived_from<Interface> T>
        const std::unordered_set<T>& get() const;
        template<std::derived_from<Interface> T>
        std::unordered_set<T>& get() const;

        /**
         * @brief Gets if the set contains any items of a desired type.
         * 
         * @return If the set contains any items of a desired type.
         */
        template<std::derived_from<Interface> T>
        bool contains_type() const noexcept;

        /**
         * @brief Gets if the set contains a specific item.
         * 
         * @param value The value being checked for.
         * @return If the set contains the specific item.
         */
        template<std::derived_from<Interface> T>
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
         * @brief Gets the desired iterator for a type stored in this container.
         * 
         * @return The desired iterator.
         * 
         * Throws an exception if the container doesn't contain an item of the desired type.
         */
        const_iterator cbegin() const noexcept;
        const_iterator begin() const noexcept;
        const_iterator cend() const noexcept;
        const_iterator end() const noexcept;
    };
}

#include "foundation/containers/InterfacedErasedSet.tpp"
