/*
    Size.hpp

    Template implementation for the Size class
*/

#include "Types/Size.hpp"

template <typename T>
Size_<T>::Size_(T width, T height) 
    : width(width), height(height) {}

template<typename T>
T Size_<T>::area() const {
    return width * height;
}

template<typename Scalar, typename T>
Size_<T> operator*(const Scalar& s, const Size_<T>& size) {
    return {(T)(size.width * s), (T)(size.height * s)};
}

template<typename T>
template<typename Scalar>
Size_<T> Size_<T>::operator*(const Scalar& s) const {
    return {(T)(width * s), (T)(height * s)};
}

template<typename T>
template<typename Scalar>
void Size_<T>::operator*=(const Scalar& s) {
    width *= s;
    height *= s;
}

template<typename Scalar, typename T>
Size_<T> operator/(const Scalar& s, const Size_<T>& size) {
    return {(T)(size.width / s), (T)(size.height / s)};
}

template<typename T>
template<typename Scalar>
Size_<T> Size_<T>::operator/(const Scalar& s) const {
    return {(T)(width / s), (T)(height / s)};
}

template<typename T>
template<typename Scalar>
void Size_<T>::operator/=(const Scalar& s) {
    width /= s;
    height /= s;
}

template <typename T>
std::ostream& operator<<(std::ostream& o, const Size_<T>& size) {
    o << "(" << size.width << "x" << size.height << ")";
    return o;
}
