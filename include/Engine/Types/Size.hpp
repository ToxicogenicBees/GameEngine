/*
    Size.hpp

    Declaration for the Size class
*/

#pragma once

#include <ostream>

template <typename T>
struct Size_;

// Type aliases
using Size  = Size_<size_t>;
using Sizef = Size_<float>;
using Sized = Size_<double>;
using Sizei = Size_<int>;

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
    Size_(T width = T(0), T height = T(0));
    
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
    template<typename U>
    friend std::ostream& operator<<(std::ostream& o, const Size_<U>& size);
};

#include "Types/Size.tpp"
