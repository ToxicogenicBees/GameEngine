/*
    Handle.hpp

    Declaration of a concept for a storage handle.
*/

#pragma once

#include <cstdint>
#include <concepts>

namespace toxico {
    template<typename T>
    concept Handle = requires(const T& h) {
        typename T::index_type;

        { h.index() } -> std::same_as<typename T::index_type>;
        { h.generation() } -> std::same_as<typename T::index_type>;

        T{
            std::declval<typename T::index_type>(),
            std::declval<typename T::index_type>()
        };
    };
}
