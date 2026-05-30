/*
    Object.cpp

    Implementation of a core engine Object, of which all items are derived
*/

#include "Core/Object.hpp"

bool Object::isDestroyed() {
    return destroyed_;
}

void Object::destroy() {
    if (!destroyed_) {
        destroyed_ = true;
        onDestroy();
    }
}

const Guid& Object::guid() const {
    return GUID_;
}
