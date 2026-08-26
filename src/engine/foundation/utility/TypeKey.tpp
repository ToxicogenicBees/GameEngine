/*
    TypeKey.hpp

    Declaration of a type key, where the order of the types matters.
*/

#include <algorithm>

namespace toxico {
    template<typename... Types>
    TypeKey TypeKey::of() noexcept {
        TypeKey result;

        (result.types_.push_back(typeid(Types)), ...);
        std::sort(result.types_.begin(), result.types_.end());

        return result;
    }

    template<typename T>
    bool TypeKey::contains() const noexcept {
        return contains(typeid(T));
    }
}
