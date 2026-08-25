/*
    TypeSet.hpp

    Declaration of a type set, storing multiple objects of the same template with different underlying types.
*/

#pragma once

#include <unordered_map>
#include <typeindex>
#include <any>

namespace toxico {
    template<template<typename> typename Object>
    class TypeSet {
    private:
        using Objects = std::unordered_map<std::type_index, std::any>;
        Objects objects_;

    public:
        using const_iterator = Objects::const_iterator;
        using iterator = Objects::iterator;

        /**
         * @brief Gets the properly typed object stored in this set.
         * 
         * @return The properly typed object stored in this set.
         * 
         * Throws an exception if the set doesn't have an object of the desired type.
         */
        template<typename T>
        const Object<T>& get() const;
        
        /**
         * @brief Gets the properly typed object stored in this set.
         * 
         * @return The properly typed object stored in this set.
         * 
         * Throws an exception if the set doesn't have an object of the desired type.
         */
        template<typename T>
        Object<T>& get();

        /**
         * @brief Inserts an item into the set.
         * 
         * @param object The object being inserted.
         * 
         * Throws an invalid argument exception if there already exists an item of
         * the desired type in the set.
         */
        template<typename T>
        Object<T>& insert(const Object<T>& object);

        /**
         * @brief Emplaces an item into the set.
         * 
         * @param args The constructor arguments for the object being emplaced.
         * 
         * Throws an invalid argument exception if there already exists an item of
         * the desired type in the set.
         */
        template<typename T, typename... Args>
        Object<T>& emplace(Args&&... args);

        /**
         * @brief Gets if an object of a specific type exists in this set.
         * 
         * @return If the object exists.
         */
        template<typename T>
        bool contains() const noexcept;

        /**
         * @brief Removes an item of a specific type from the set.
         */
        template<typename T>
        void erase() noexcept;

        /**
         * @brief Removes all items of every type from the set.
         */
        void clear() noexcept;

        /**
         * @brief Gets the number of unique types in this set.
         * 
         * @return The number of unique types in this set.
         */
        std::size_t size() const noexcept;
        
        /**
         * @brief Gets the desired iterator for this tile's indices.
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

#include "foundation/containers/TypeSet.tpp"
