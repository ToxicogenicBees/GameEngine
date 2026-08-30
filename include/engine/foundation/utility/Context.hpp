/*
    Context.hpp

    Declaration of a context holder, storing references to preconstructed objects.
*/

#pragma once

#include "foundation/concepts/ContainsType.hpp"
#include <utility>

namespace toxico {
    template<typename... Types>
    class Context {
    private:
        std::tuple<Types&...> context_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param args Items being binded to this context.
         */
        Context(Types& ...args);

        /**
         * @brief Gets an item from this context.
         * 
         * @return The item in this context.
         */
        template<typename T>
        requires ContainsType_v<T, Types...>
        const T& get() const;

        /**
         * @brief Gets an item from this context.
         * 
         * @return The item in this context.
         */
        template<typename T>
        requires ContainsType_v<T, Types...>
        T& get();
    };
}

#include "foundation/utility/Context.tpp"
