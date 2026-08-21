/*
    Transform3D.cpp

    Implementation of a 3D transformation info component.
*/

#include "core/math/Transform3D.hpp"

namespace toxico {
    void Transform3D::commit() {
        position.commit();
        scale.commit();
        rotation.commit();
    }
}

