/*
    ErasedMapIterator.hpp

    Declaration of an iterator for an erased map.
*/

#pragma once

#include <unordered_map>
#include <type_traits>
#include <typeindex>
#include <any>

namespace toxico {
    template<typename Key, typename T>
    class ErasedMapIterator {
    private:
        using Iterator = std::unordered_map<Key, std::any>::const_iterator;

        Iterator current_;
        Iterator end_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param current An iterator for the erased map's data.
         * @param end The iterator at the end of the erased map's data.
         */
        ErasedMapIterator(Iterator current, Iterator end) noexcept;

        /**
         * @brief Comparison operator.
         * 
         * @param other Another iterator.
         * @return If the two iterators are the same.
         */
        bool operator==(const ErasedMapIterator& other) const noexcept;

        /**
         * @brief Post-increment operator.
         * 
         * @return A reference to the modified iterator.
         */
        ErasedMapIterator& operator++();

        /**
         * @brief Dereference operator.
         * 
         * @return A reference to the object at this iterator.
         */
        std::pair<Key, const T&> operator*();
    };
}

#include "foundation/containers/iterators/ErasedMapIterator.tpp"
