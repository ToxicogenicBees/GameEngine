/*
    Transform2D.cpp

    Implementation of a 2D transformation info component.
*/

#include "core/math/Transform2D.hpp"

namespace toxico {
    void Transform2D::commit() {
        position.commit();
        scale.commit();
        rotation.commit();
    }
}
