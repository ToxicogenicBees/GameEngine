/*
    contains_type.hpp

    Declaration of a concept that gets if a type is found in a list of types.
*/

#pragma once

namespace toxico {
    template <typename T, typename... Ts>
    struct ContainsType : std::bool_constant<(std::is_same_v<T, Ts> || ...)> {};
    
    template <typename T, typename... Ts>
    inline constexpr bool ContainsType_v = ContainsType<T, Ts...>::value;
}
