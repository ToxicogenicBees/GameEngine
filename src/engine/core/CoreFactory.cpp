/*
    CoreFactory.cpp

    Implementation of a core factory, building the low-level core engine layer.
*/

#include "core/CoreFactory.hpp"
#include "core/Core.hpp"
#include "core/logging/LoggerBase.hpp"
#include "core/logging/ConsoleLogger.hpp"
#include "core/jobs/JobScheduler.hpp"
#include "core/ecs/ECS.hpp"

namespace toxico {
    std::unique_ptr<Core> CoreFactory::create() {
        auto core = std::make_unique<Core>();

        core->addModule<LoggerBase>(std::make_unique<ConsoleLogger>());
        core->addModule<JobScheduler>(std::make_unique<JobScheduler>());
        core->addModule<ECS>(std::make_unique<ECS>());

        return core;
    }
}
