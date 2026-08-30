/*
    Stringable.hpp

    A concept for an object that provides a toString() member.
*/

#pragma once

#include <concepts>
#include <string>

namespace toxico {
    template<typename T>
    concept Stringable = requires(const T& val) {
        { val.toString() } -> std::convertible_to<std::string>;
    };
}
