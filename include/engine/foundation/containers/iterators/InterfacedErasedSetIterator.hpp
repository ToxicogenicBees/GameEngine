/*
    InterfacedErasedSetIterator.hpp

    Declaration of an iterator for an interfaced erased set.
*/

#pragma once

#include "foundation/containers/utility/interfaces/IInterfacedErasedBucket.hpp"
#include <unordered_map>
#include <type_traits>
#include <typeindex>
#include <memory>

namespace toxico {
    template<typename Interface>
    class InterfacedErasedSetIterator {
    private:
        using StorageType = std::unordered_map<std::type_index, std::unique_ptr<IInterfacedErasedBucket<Interface>>>;
        using Iterator = typename StorageType::const_iterator;

        Iterator iterator_;
        std::size_t bucket_index_ = 0;

    public:
        /**
         * @brief Constructor.
         * 
         * @param iterator An iterator for the interfaced erased set's data.
         */
        InterfacedErasedSetIterator(Iterator iterator) noexcept;

        /**
         * @brief Comparison operator.
         * 
         * @param other Another iterator.
         * @return If the two iterators are the same.
         */
        bool operator==(const InterfacedErasedSetIterator& other) const noexcept;

        /**
         * @brief Post-increment operator.
         * 
         * @return A reference to the modified iterator.
         */
        InterfacedErasedSetIterator& operator++();

        /**
         * @brief Dereference operator.
         * 
         * @return A reference to the object at this iterator.
         */
        const Interface& operator*();

        /**
         * @brief Structure pointer dereference operator.
         * 
         * @return A pointer to the object at this iterator.
         */
        const Interface* operator->();
    };
}

#include "foundation/containers/iterators/InterfacedErasedSetIterator.tpp"
