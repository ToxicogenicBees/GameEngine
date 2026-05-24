/*
    Object.hpp

    Declaration of an abstract engine object class
*/

#include "Core/Object.hpp"

const Transform& Object::transform() const {
    return transform_;
}

Transform& Object::transform() {
    return transform_;
}
