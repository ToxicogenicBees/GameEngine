/*
    ErasedSetIterator.hpp

    Declaration of an iterator for an erased set.
*/

#pragma once

#include <unordered_map>
#include <type_traits>
#include <typeindex>
#include <memory>

namespace toxico {
    template<bool Const, typename Interface>
    class InterfacedErasedSetIterator_ {
    private:
        using StorageType = std::unordered_map<std::type_index, std::unique_ptr<Interface>>;
        using Reference = std::conditional_t<Const, const Interface&, Interface&>;
        using Pointer = std::conditional_t<Const, const Interface*, Interface*>;
        using StorageIter = std::conditional_t<Const, typename StorageType::const_iterator, typename StorageType::iterator>;
        
        StorageIter iterator_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param iterator An iterator for an InterfacedErasedSet.
         */
        InterfacedErasedSetIterator_(StorageIter iterator) noexcept;

        /**
         * @brief Comparison operator.
         *
         * @param other Another iterator.
         * @return If these two iterators are the same.
         */
        bool operator==(const InterfacedErasedSetIterator_& other) const noexcept;

        /**
         * @brief Post-increment operator.
         * 
         * @return The modified iterator.
         */
        InterfacedErasedSetIterator_& operator++() noexcept;

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

    template<typename Interface>
    using ConstInterfacedErasedSetIterator = InterfacedErasedSetIterator_<true, Interface>;
    template<typename Interface>
    using InterfacedErasedSetIterator = InterfacedErasedSetIterator_<false, Interface>;
}

#include "foundation/containers/erased/iterators/InterfacedErasedSetIterator.tpp"