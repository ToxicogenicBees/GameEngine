/*
    Image.cpp

    Implementation of an image object.
*/

#include "core/graphics/Image.hpp"

namespace toxico {
    template<std::input_iterator InputIter>
    Image::Image(InputIter begin, InputIter end, Size size, GridOrder order)
        : pixels_(begin, end, size, order) {}
}
