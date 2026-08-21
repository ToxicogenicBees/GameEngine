/*
    TypeMap.hpp

    Declaration of a map, a collection of objects of the same base type.
*/

#pragma once

#include <type_traits>
#include <unordered_map>
#include <typeindex>
#include <memory>

namespace toxico {
    template<typename Base>
    class TypeMap {
    private:
        using Data = std::unordered_map<std::type_index, std::unique_ptr<Base>>;
        Data data_;

    public:
        using const_iterator = Data::const_iterator;
        using iterator = Data::iterator;

        /**
         * @brief Inserts an item into the map.
         * 
         * @param value The item being inserted.
         * 
         * Throws a runtime exception if an item of this type already exists.
         */
        template<typename Derived, typename... Args>
        requires std::is_base_of_v<Base, Derived>
        Derived* insert(std::unique_ptr<Derived> value);
    
        /**
         * @brief Emplaces an item into the map.
         * 
         * @param args The template arguments for this item.
         * 
         * Throws a runtime exception if an item of this type already exists.
         */
        template<typename Derived, typename... Args>
        requires std::is_base_of_v<Base, Derived>
        Derived* emplace(Args&& ...args);

        /**
         * @brief Gets if an item is in the map.
         * 
         * @return If the item is in the map.
         */
        template<typename Derived>
        bool contains() const noexcept;

        /**
         * @brief Gets an item to the map.
         * 
         * @return The item, or nullptr if it wasn't contained in the map.
         */
        template<typename Derived>
        requires std::is_base_of_v<Base, Derived>
        const Derived* get() const noexcept;

        /**
         * @brief Gets an item to the map.
         * 
         * @return The item, or nullptr if it wasn't contained in the map.
         */
        template<typename Derived>
        requires std::is_base_of_v<Base, Derived>
        Derived* get() noexcept;

        /**
         * @brief Removes an item from the map.
         */
        template<typename Derived>
        requires std::is_base_of_v<Base, Derived>
        void erase() noexcept;

        /**
         * @brief Gets the desired iterator for this type map's items.
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

#include "foundation/containers/TypeMap.tpp"
