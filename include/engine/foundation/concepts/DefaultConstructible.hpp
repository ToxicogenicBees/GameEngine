/*
    DefaultConstructible.hpp

    Declaration of a concept for an object with a default constructor.
*/

#pragma once

#include <cstdint>
#include <concepts>

namespace toxico {
    template<typename T>
    concept DefaultConstructible = requires(const T& dc) {
        // Must be default constructable
        T{};
    };
}
