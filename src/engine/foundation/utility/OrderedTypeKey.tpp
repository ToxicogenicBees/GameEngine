/*
    OrderedTypeKey.hpp

    Declaration of a type key, where the order of the types matters.
*/

#include <algorithm>

namespace toxico {
    template<typename... Types>
    OrderedTypeKey OrderedTypeKey::of() noexcept {
        OrderedTypeKey result;

        (result.types_.push_back(typeid(Types)), ...);

        return result;
    }

    template<typename T>
    bool OrderedTypeKey::contains() const noexcept {
        return contains(typeid(T));
    }
}
