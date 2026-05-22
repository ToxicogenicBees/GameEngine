/*
    Size.hpp

    Declaration and implementation for the Size class
*/

#pragma once

template <typename T>
struct Size_ {
    T width;
    T height;

    /**
     * @brief Constructor
     * 
     * @param width The horizontal size
     * @param height The vertical size
     */
    Size_(T width = T(0), T height = T(0)) 
        : width(width), height(height) {}
    
    /**
     * @brief Gets the area of a rectangle of this size
     * 
     * @return The area of a rectangle of this size
     */
    T area() const;

    /***
     * @brief Overloaded multiplication operator
     * 
     * @param s A multiplier value
     * 
     * @return The scaled size
     */
    template<typename Scalar>
    Size_ operator*(const Scalar& s) const;

    /***
     * @brief Overloaded chained multiplication + assignment operator
     * 
     * @param s A multiplier value
     */
    template<typename Scalar>
    void operator*=(const Scalar& s);

    /***
     * @brief Overloaded division operator
     * 
     * @param s A multiplier value
     * 
     * @return The scaled size
     */
    template<typename Scalar>
    Size_ operator/(const Scalar& s) const;
    
    /***
     * @brief Overloaded chained division + assignment operator
     * 
     * @param s A multiplier value
     */
    template<typename Scalar>
    void operator/=(const Scalar& s);

    /***
     * @brief Overloaded insertion operator
     * 
     * @param o A reference to an output stream
     * @param size The size being output to the stream
     * 
     * @result A reference to the output stream being output to
     */
    friend std::ostream& operator<<(std::ostream& o, const Size_& size) {
        o << "(" << size.width << "x" << size.height << ")";
        return o;
    }
};

using Size = Size_<size_t>;
using Sizef = Size_<float>;
using Sized = Size_<double>;
using Sizei = Size_<int>;

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
