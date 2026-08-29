/*
    contains_type.hpp

    Declaration of a concept that gets if a type is found in a list of types.
*/

#pragma once

namespace toxico {
    template <typename T, typename... Ts>
    struct contains_type : std::bool_constant<(std::is_same_v<T, Ts> || ...)> {};
    
    template <typename T, typename... Ts>
    inline constexpr bool contains_type_v = contains_type<T, Ts...>::value;
}
