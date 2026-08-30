/*
    Loggable.hpp

    A concept for an item that can be logged.
*/

#pragma once

#include "foundation/concepts/Stringable.hpp"

namespace toxico {
    template<typename T>
    concept Loggable =
        Stringable<T> ||
        std::convertible_to<T, std::string> ||
        std::is_arithmetic_v<std::remove_cvref_t<T>>;
}
