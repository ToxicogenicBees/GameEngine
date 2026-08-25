/*
    Ray.tpp

    Template implementation of a simple ray class.
*/

namespace toxico {
    template<std::size_t N>
    constexpr Ray<N>::Ray(const Vector<double, N>& origin, const Vector<double, N>& direction)
        : origin(origin),
          direction(direction)
    {}

    template<std::size_t N>
    constexpr Ray<N>::Ray(const Vector<double, N>& direction)
        : direction(direction) {}

    template<std::size_t N>
    constexpr double Ray<N>::length() const {
        return direction.magnitude();
    }

    template<std::size_t N>
    constexpr Ray<N> Ray<N>::unit() const {
        return Ray<N>{
            origin,
            direction.normal()
        };
    }

    template<std::size_t N>
    constexpr Vector<double, N> Ray<N>::end() const {
        return origin + direction;
    }
}
