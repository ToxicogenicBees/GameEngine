/*
    DenseErasure.hpp

    Declaration of a struct containing dense vector erasure information.
*/

#pragma once

#include <cstddef>

namespace toxico {
    struct DenseErasure {
        // If the erasure went through
        bool erased = false;

        // The index that the swapped item went to/from
        size_t moved_from = 0;
        size_t moved_to = 0;
    };
}
