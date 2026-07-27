/*
    CoreFactory.cpp

    Implementation of a core factory, building the low-level core engine layer.
*/

#include "Core/CoreFactory.hpp"
#include "Core/Core.hpp"

namespace toxico {
    std::unique_ptr<Core> CoreFactory::create() {
        return std::make_unique<Core>();
    }
}
