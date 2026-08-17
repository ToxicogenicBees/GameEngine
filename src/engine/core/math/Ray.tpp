/*
    Ray.tpp

    Template implementation of a simple ray class.
*/

#include "core/math/Ray.hpp"

namespace toxico {
    template<typename Vector>
    Ray_<Vector>::Ray_(Vector origin, Vector direction)
        : direction(direction),
          origin(origin)
    {}

    template<typename Vector>
    Ray_<Vector>::Ray_(Vector direction)
        : direction(direction) {}

    template<typename Vector>
    double Ray_<Vector>::length() const {
        return direction.magnitude();
    }

    template<typename Vector>
    Ray_<Vector> Ray_<Vector>::unit() const {
        return Ray_<Vector>(origin, direction.normal());
    }

    template<typename Vector>
    Vector Ray_<Vector>::end() const {
        return origin + direction;
    }
}
