/*
    CoreFactory.cpp

    Implementation of a core factory, building the low-level core engine layer.
*/

#include "Core/CoreFactory.hpp"
#include "Core/Core.hpp"
#include "Core/Jobs/JobScheduler.hpp"

namespace toxico {
    std::unique_ptr<Core> CoreFactory::create() {
        auto core = std::make_unique<Core>();

        core->addModule<JobScheduler>(std::make_unique<JobScheduler>());

        return core;
    }
}
