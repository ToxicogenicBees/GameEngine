/*
    ErasedVectorIterator.hpp

    Declaration of an iterator for an erased vector.
*/

#pragma once

#include <type_traits>
#include <typeindex>
#include <vector>
#include <any>

namespace toxico {
    template<bool Const, typename T>
    class ErasedVectorIterator_ {
    private:
        using StorageData = std::vector<std::any>;
        using Iterator = std::conditional_t<Const, StorageData::const_iterator, StorageData::iterator>;
        using Reference = std::conditional_t<Const, const T&, T&>;
        using Pointer = std::conditional_t<Const, const T*, T*>;

        Iterator current_;
        Iterator end_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param current An iterator for the erased map's data.
         * @param end The iterator at the end of the erased map's data.
         */
        ErasedVectorIterator_(Iterator current, Iterator end) noexcept;

        /**
         * @brief Comparison operator.
         * 
         * @param other Another iterator.
         * @return If the two iterators are the same.
         */
        bool operator==(const ErasedVectorIterator_& other) const noexcept;

        /**
         * @brief Pre-increment operator.
         * 
         * @return A reference to the modified iterator.
         */
        ErasedVectorIterator_& operator++();

        /**
         * @brief Dereference operator.
         * 
         * @return A reference to the object at this iterator.
         */
        Reference operator*();

        /**
         * @brief Structure pointer dereference operator.
         * 
         * @return A pointer to the object at this iterator.
         */
        Pointer operator->();
    };

    template<typename T>
    using ConstErasedVectorIterator = ErasedVectorIterator_<true, T>;
    template<typename T>
    using ErasedVectorIterator = ErasedVectorIterator_<false, T>;
}

#include "foundation/containers/iterators/ErasedVectorIterator.tpp"
