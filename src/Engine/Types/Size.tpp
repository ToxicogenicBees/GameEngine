/*
    Size.hpp

    Template implementation for the Size class
*/

#include "Types/Size.hpp"

/**
 * @brief Constructor
 * 
 * @param width The horizontal size
 * @param height The vertical size
 */
template <typename T>
Size_<T>::Size_(T width, T height) 
    : width(width), height(height) {}

/**
 * @brief Gets the area of a rectangle of this size
 * 
 * @return The area of a rectangle of this size
 */
template<typename T>
T Size_<T>::area() const {
    return width * height;
}

/***
 * @brief Overloaded multiplication operator
 * 
 * @param s A multiplier value
 * @param size A size object
 * 
 * @return The scaled size
 */
template<typename Scalar, typename T>
Size_<T> operator*(const Scalar& s, const Size_<T>& size) {
    return {(T)(size.width * s), (T)(size.height * s)};
}

/***
 * @brief Overloaded multiplication operator
 * 
 * @param s A multiplier value
 * 
 * @return The scaled size
 */
template<typename T>
template<typename Scalar>
Size_<T> Size_<T>::operator*(const Scalar& s) const {
    return {(T)(width * s), (T)(height * s)};
}

/***
 * @brief Overloaded chained multiplication + assignment operator
 * 
 * @param s A multiplier value
 */
template<typename T>
template<typename Scalar>
void Size_<T>::operator*=(const Scalar& s) {
    width *= s;
    height *= s;
}

/***
 * @brief Overloaded division operator
 * 
 * @param s A multiplier value
 * @param size A size object
 * 
 * @return The scaled size
 */
template<typename Scalar, typename T>
Size_<T> operator/(const Scalar& s, const Size_<T>& size) {
    return {(T)(size.width / s), (T)(size.height / s)};
}

/***
 * @brief Overloaded division operator
 * 
 * @param s A multiplier value
 * 
 * @return The scaled size
 */
template<typename T>
template<typename Scalar>
Size_<T> Size_<T>::operator/(const Scalar& s) const {
    return {(T)(width / s), (T)(height / s)};
}

/***
 * @brief Overloaded chained division + assignment operator
 * 
 * @param s A multiplier value
 */
template<typename T>
template<typename Scalar>
void Size_<T>::operator/=(const Scalar& s) {
    width /= s;
    height /= s;
}

/***
 * @brief Overloaded insertion operator
 * 
 * @param o A reference to an output stream
 * @param size The size being output to the stream
 * 
 * @result A reference to the output stream being output to
 */
template <typename T>
std::ostream& operator<<(std::ostream& o, const Size_<T>& size) {
    o << "(" << size.width << "x" << size.height << ")";
    return o;
}
