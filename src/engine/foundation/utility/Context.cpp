/*
    Context.cpp

    Implementation of a context holder, storing references to preconstructed objects.
*/

#include "foundation/utility/Context.hpp"

namespace toxico {
    void Context::clear() {
        context_.clear();
    }
}
