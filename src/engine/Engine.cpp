/*
    Engine.cpp

    Implementation of a composition of engine layers working together to form an engine.
*/

#include "Engine.hpp"
#include "platform/PlatformFactory.hpp"
#include "core/CoreFactory.hpp"

namespace toxico {
    Engine::Engine()
        : platform_(PlatformFactory::create()),
          core_(CoreFactory::create())
    {}
}
