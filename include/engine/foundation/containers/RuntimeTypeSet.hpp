/*
    RuntimeTypeSet.hpp

    Declaration of a type set, storing a set of objects derived from the same base type.
*/

#pragma once

#include <unordered_map>
#include <typeindex>
#include <memory>

namespace toxico {
    template<typename Base>
    class RuntimeTypeSet {
    private:
        using Objects = std::unordered_map<std::type_index, std::unique_ptr<Base>>;
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
        template<typename Derived>
        requires std::is_base_of_v<Base, Derived>
        const Derived& get() const;
        
        /**
         * @brief Gets the properly typed object stored in this set.
         * 
         * @return The properly typed object stored in this set.
         * 
         * Throws an exception if the set doesn't have an object of the desired type.
         */
        template<typename Derived>
        requires std::is_base_of_v<Base, Derived>
        Derived& get();

        /**
         * @brief Gets the properly typed object stored in this set.
         * 
         * @param type_index The type index of the object being fetched.
         * @return The properly typed object stored in this set.
         * 
         * Throws an exception if the set doesn't have an object of the desired type.
         */
        const Base& get(const std::type_index& type_index) const;
        
        /**
         * @brief Gets the properly typed object stored in this set.
         * 
         * @param type_index The type index of the object being fetched.
         * @return The properly typed object stored in this set.
         * 
         * Throws an exception if the set doesn't have an object of the desired type.
         */
        Base& get(const std::type_index& type_index);

        /**
         * @brief Inserts an item into the set.
         * 
         * @param object The object being inserted.
         * 
         * Throws an invalid argument exception if there already exists an item of
         * the desired type in the set.
         */
        template<typename Derived>
        requires std::is_base_of_v<Base, Derived>
        void insert(const Derived& object);

        /**
         * @brief Inserts an item into the set.
         * 
         * @param object The object being inserted.
         * 
         * Throws an invalid argument exception if there already exists an item of
         * the desired type in the set.
         */
        template<typename Derived>
        requires std::is_base_of_v<Base, Derived>
        void insert(std::unique_ptr<Derived> object);

        /**
         * @brief Emplaces an item into the set.
         * 
         * @param args The constructor arguments for the object being emplaced.
         * 
         * Throws an invalid argument exception if there already exists an item of
         * the desired type in the set.
         */
        template<typename Derived, typename... Args>
        requires std::is_base_of_v<Base, Derived>
        Derived& emplace(Args&&... args);

        /**
         * @brief Gets if an object of a specific type exists in this set.
         * 
         * @return If the object exists.
         */
        template<typename Derived>
        requires std::is_base_of_v<Base, Derived>
        bool contains() const noexcept;

        /**
         * @brief Removes an item of a specific type from the set.
         */
        template<typename Derived>
        requires std::is_base_of_v<Base, Derived>
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
         * @brief Gets the desired iterator for this set's objects.
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

#include "foundation/containers/RuntimeTypeSet.tpp"
