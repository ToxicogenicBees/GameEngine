/*
    Context.tpp

    Template implementation of a context holder, storing references to preconstructed objects.
*/

#include <functional>

namespace toxico {
    template<typename... Types>
    Context<Types...>::Context(Types& ...args)
        : context_(args...) {}

    template<typename... Types>
    template<typename T>
    requires ContainsType_v<T, Types...>
    const T& Context<Types...>::get() const {
        return std::get<const T&>(context_);
    }

    template<typename... Types>
    template<typename T>
    requires ContainsType_v<T, Types...>
    T& Context<Types...>::get() {
        return std::get<T&>(context_);
    }
}
