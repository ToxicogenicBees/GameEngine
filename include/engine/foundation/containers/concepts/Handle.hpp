/*
    Handle.hpp

    Declaration of a concept for a storage handle.
*/

#pragma once

#include <cstdint>
#include <concepts>

namespace toxico {
    template<typename T>
    concept Handle = requires(const T& h, uint32_t index, uint32_t generation) {
        { h.index() } -> std::same_as<uint32_t>;
        { h.generation() } -> std::same_as<uint32_t>;
        T{index, generation};
    };
}
