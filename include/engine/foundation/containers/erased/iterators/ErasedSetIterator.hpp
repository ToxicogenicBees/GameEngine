/*
    ErasedSetIterator.hpp

    Declaration of an iterator for an erased set.
*/

#pragma once

#include <unordered_map>
#include <type_traits>
#include <typeindex>
#include <any>

namespace toxico {
    template<bool Const>
    class ErasedSetIterator_ {
    private:
        using StorageType = std::unordered_map<std::type_index, std::any>;
        using Reference = std::conditional_t<Const, const std::any&, std::any&>;
        using Pointer = std::conditional_t<Const const std::any*, std::any*>;
        using StorageIter = std::conditional_t<Const, StorageType::const_iterator, StorageType::iterator>;

        StorageIter iterator_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param iterator An iterator for an ErasedSet.
         */
        ErasedSetIterator_(StorageIter iterator) noexcept;

        /**
         * @brief Comparison operator.
         *
         * @param other Another iterator.
         * @return If these two iterators are the same.
         */
        bool operator==(const ErasedSetIterator_& other) const noexcept;

        /**
         * @brief Post-increment operator.
         * 
         * @return The modified iterator.
         */
        ErasedSetIterator_& operator++() noexcept;

        /**
         * @brief Dereference operator.
         * 
         * @return A reference to the set item.
         */
        Reference operator*();

        /**
         * @brief Structure pointer dereference operator.
         * 
         * @return A pointer to the set item.
         */
        Pointer operator->();
    };

    using ConstErasedSetIterator = ErasedSetIterator_<true>;
    using ErasedSetIterator = ErasedSetIterator_<false>;
}

#include "foundation/containers/erased/iterators/ErasedSetIterator.tpp"
