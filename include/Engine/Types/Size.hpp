/*
    Size.hpp

    Declaration for the Size class
*/

#pragma once

#include <ostream>
#include <stdint.h>

class Size {
private:
    size_t width_;
    size_t height_;

public:
    /**
     * @brief Constructor
     * 
     * @param width The horizontal size
     * @param height The vertical size
     */
    Size(size_t width = 0, size_t height = 0);

    /**
     * @brief Sets the size.
     * 
     * @param width The desired width
     * @param height The desired height
     */
    void setSize(size_t width, size_t height);

    /**
     * @brief Gets the width of the size.
     * 
     * @return The width of the size.
     */
    size_t width() const;

    /**
     * @brief Sets the width.
     * 
     * @param width The desired width
     */
    void setWidth(size_t width);

    /**
     * @brief Gets the height of the size.
     * 
     * @return The height of the size.
     */
    size_t height() const;

    /**
     * @brief Sets the height.
     * 
     * @param height The desired height
     */
    void setHeight(size_t height);
    
    /**
     * @brief Gets the area of a rectangle of this size
     * 
     * @return The area of a rectangle of this size
     */
    size_t area() const;

    /***
     * @brief Overloaded multiplication operator
     * 
     * @param s A multiplier value
     * @param size A size object
     * 
     * @return The scaled size
     */
    template<typename Scalar>
    friend Size operator*(const Scalar& s, const Size& size);

    /***
     * @brief Overloaded multiplication operator
     * 
     * @param s A multiplier value
     * 
     * @return The scaled size
     */
    template<typename Scalar>
    Size operator*(const Scalar& s) const;

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
     * @param size A size object
     * 
     * @return The scaled size
     */
    template<typename Scalar>
    friend Size operator/(const Scalar& s, const Size& size);

    /***
     * @brief Overloaded division operator
     * 
     * @param s A multiplier value
     * 
     * @return The scaled size
     */
    template<typename Scalar>
    Size operator/(const Scalar& s) const;
    
    /***
     * @brief Overloaded chained division + assignment operator
     * 
     * @param s A multiplier value
     */
    template<typename Scalar>
    void operator/=(const Scalar& s);

    /**
     * @brief Compare two size object.
     * 
     * @result If the two sizes are equal.
     */
    bool operator==(const Size& size) const;

    /***
     * @brief Overloaded insertion operator
     * 
     * @param o A reference to an output stream
     * @param size The size being output to the stream
     * 
     * @result A reference to the output stream being output to
     */
    friend std::ostream& operator<<(std::ostream& o, const Size& size) {
        o << "(" << size.width_ << "x" << size.height_ << ")";
        return o;
    }
};

#include "Types/Size.tpp"
