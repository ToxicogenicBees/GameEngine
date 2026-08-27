/*
    ErasedVector.hpp

    Declaration of a type-erased collection of arbitrary data, stored in {numerical index, value} pairs.
*/

#pragma once

#include "foundation/containers/iterators/ErasedVectorIterator.hpp"
#include "foundation/utility/IterationRange.hpp"
#include <vector>
#include <any>

namespace toxico {
    class ErasedVector {
    private:
        using Data = std::vector<std::any>;
        Data data_;

    public:
        template<typename T>
        using const_iterator = ConstErasedVectorIterator<T>;
        template<typename T>
        using iterator = ErasedVectorIterator<T>;
    
        using data_const_iterator = Data::const_iterator;
        using data_iterator = Data::iterator;

        /**
         * @brief Inserts an item into the vector.
         * 
         * @param value The item being inserted.
         * @return An iterator to the key the type maps to, and a bool signaling if the insertion succeeded.
         */
        template<typename T>
        void push_back(const T& value);

        /**
         * @brief Emplaces an item into the vector.
         * 
         * @param args The constructor arguments for the item.
         * @return An iterator to the key the type maps to, and a bool signaling if the emplacement succeeded.
         */
        template<typename T, typename... Args>
        T& emplace_back(Args&& ...args);

        /**
         * @brief Erases an item from the vector.
         * 
         * @param pos The position being erased.
         * @return The iterator just after the removed element.
         */
        data_iterator erase(data_const_iterator pos);

        /**
         * @brief Erases a range from the vector.
         * 
         * @param first The beginning of the range.
         * @param last The end of the range.
         * @return The iterator just after the last removed element.
         */
        data_iterator erase(data_const_iterator first, data_const_iterator last);

        /**
         * @brief Pops the last element from the vector.
         */
        void pop_back() noexcept;

        /**
         * @brief Gets the item at an index, as a specific type.
         * 
         * @param index The desired vector index.
         * @return The item of that type.
         * 
         * Throws an error if the index is out of bounds.
         * Throws an error if the cast is bad.
         */
        template<typename T>
        const T& at(std::size_t index) const;
        template<typename T>
        T& at(std::size_t index);

        /**
         * @brief Gets the item at the front of the vector.
         * 
         * @return The item at the front of the vector.
         * 
         * Throws an exception if there are no items in the vector.
         * Throws an exception if the cast is bad.
         */
        template<typename T>
        const T& front() const;
        template<typename T>
        T& front();

        /**
         * @brief Gets the item at the back of the vector.
         * 
         * @return The item at the back of the vector.
         * 
         * Throws an exception if there are no items in the vector.
         * Throws an exception if the cast is bad.
         */
        template<typename T>
        const T& back() const;
        template<typename T>
        T& back();

        /**
         * @brief Resizes the vector.
         * 
         * @param size The desired size.
         */
        void resize(std::size_t size);

        /**
         * @brief Reserves space in the vector.
         * 
         * @param size The space being reserved.
         */
        void reserve(std::size_t size);

        /**
         * @brief Gets if the vector is empty.
         * 
         * @return If the vector is empty.
         */
        bool empty() const noexcept;

        /**
         * @brief Gets the capacity of the vector.
         * 
         * @return The capacity of the vector.
         */
        std::size_t capacity() const noexcept;

        /**
         * @brief Gets the size of the vector.
         * 
         * @return The size of the vector.
         */
        std::size_t size() const noexcept;

        /**
         * @brief Clears the vector.
         */
        void clear();

        /**
         * @brief Gets an iteration range over all items of a specific type.
         * 
         * @return The desired iteration range.
         */
        template<typename T>
        IterationRange<const_iterator<T>> iterate() const noexcept;
        template<typename T>
        IterationRange<iterator<T>> iterate() noexcept;
    };
}

#include "foundation/containers/ErasedVector.tpp"
