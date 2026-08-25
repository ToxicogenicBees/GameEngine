/*
    Component.hpp

    Declaration of a concept for a component object.
*/

#pragma once

#include <concepts>

namespace toxico {
    template<typename T>
    concept Component = requires {
        // Must have a default constructor
        requires std::default_initializable<T>;

        // Must be movable
        requires std::movable<T>;

        // Must be copyable
        requires std::copyable<T>;
    };
}
